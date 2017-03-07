#include "s5pv210.h"
/*	i2s功能初始化 */
void i2s_init(void)
{
	int N;
	// 配置引脚用于i2s功能
	GPICON = 0x22222222;

	/*	设置i2s相关时钟
		step 1: EPLL output 67.7MHz (see p361 of s5pv210.pdf)
		EPLL_CON0/ EPLL_CON1, R/W, Address = 0xE010_0110/0xE010_0114)
		FOUT = (MDIV+K/65536) X FIN / (PDIV X 2SDIV)
		Fout = (0x43+0.7)*24M / (3*2^3) = 80*24M/24 = 67.7MHz */
	EPLL_CON0 = 0xA8430303;		// MPLL_FOUT = 67.7MHz
	EPLL_CON1 = 0xBCEE;			// from linux kernel setting

	/*	step 2: Mux_I2S  AUDIO subsystem clock selection (see P1868 P1875 of s5pv210.pdf) */
					// 1 = FOUT_EPLL	MUXI2S_A 00 = Main CLK
	CLK_SRC0 = 0x10001111;
	//ASS_CLK_DIV = 1 << 4;
	CLK_CON = 0x1;


	/*	设置i2s控制器
		step 3:  Divider of IIS (67.7 -> 11.289MHz)
		N + 1 = (67.7MHz) / (256 * 44.1KHz) = 5.99
		IISCDCLK  11.289MHz = 44.1K * 256fs
		IISSCLK    1.4112MHz = 44.1K * 32fs
		IISLRCLK   44.1KHz*/
	N = 5;
	IISPSR = (1 << 15) | (N << 8);

	/*	IIS interface active (start operation).  1 = Active */
	IISCON |= (1 << 0) | (1 << 31);

	/*	[9:8] 10 = Transmit and receive simultaneous mode
		1 = Using I2SCLK     (use EPLL) */
	IISMOD = (1 << 9) | (0 << 8) | (1 << 10);

}

/*	通过i2c写数据 */
void i2c_write(int slave_addr, int addr, int data)
{
	I2CDS0 = slave_addr;

	/*	bit[7:6]: 主机发送器
		bit[5]:发出s信号和I2CDS0里的从机地址
		bit[4]:使能tx/rx */
	I2CSTAT0 = 0xF0;


	while ((I2CCON0 & 0x10) == 0);					// 等待数据发送
	while ((I2CSTAT0 & 0x1));						// 等待从机发来ACK


	/*	发7bit地址和9bit数据 */
	I2CDS0 = (addr << 1) | ((data >> 8) & 0x0001);
	I2CCON0 &= ~(1 << 4);							// 清中断
	while ((I2CCON0 & 0x10) == 0);					// 等待数据发送
	while ((I2CSTAT0 & 0x1));						// 等待从机发来ACK
	I2CDS0 = (data & 0x00FF);

	I2CCON0 &= ~(1 << 4);							// 清中断
	while ((I2CCON0 & 0x10) == 0);					// 等待数据发送
	while ((I2CSTAT0 & 0x1));						// 等待从机发来ACK



	/*	bit[7:6]: 主机发送器
		bit[5]: 发出p信号
		bit[4]: 使能tx/rx */
	I2CSTAT0 = 0xD0;
	I2CCON0 &= ~(1 << 4);							// 清中断

	/*	延时等待 */
	int i = 0;
	for(i=0;i<50;i++);

}

/*	初始化i2c */
void i2c_init(void)
{
	/*	配置引脚用于i2c功能 */
	rGPD1CON &= ~(0xFF);
	rGPD1CON |= 0x22;
	GPD1PUD &= ~(0xF);		// 关闭上拉和下拉使能

	/*	bit[7] = 1: Enable ACK
		bit[6] = 0: Prescaler IICCLK=PCLK/16
		bit[5] = 1: Enable interrupt
		bit[0:3] = 0xf:Transmit clock value = IICCLK/(15+1) */
	I2CCON0  = (1 << 7) | (0 << 6) | (1 << 5) | (0xF);

	/*	bit[4] = 1: 使能接收和发送功能 */
	I2CSTAT0 = 0x10;
}

/*	初始化vm8960 */
void vm8960_init(void)
{
	/*	重置 */
	i2c_write(WM8960_DEVICE_ADDR, 0XF, 0x0);

	/*	设置电源*/
	i2c_write(WM8960_DEVICE_ADDR, 0x19, ((1 << 8) | (1 << 7) | (1 << 6)));
	i2c_write(WM8960_DEVICE_ADDR, 0X1A, ((1 << 8) | (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3)));
	i2c_write(WM8960_DEVICE_ADDR, 0x2F, ((1 << 3) | (1 << 2)));

	/*	设置时钟 */
	i2c_write(WM8960_DEVICE_ADDR, 0x4, 0x0);

	/*	设置Class D开关时钟*/
	i2c_write(WM8960_DEVICE_ADDR, 0x8, (7 << 6));
	i2c_write(WM8960_DEVICE_ADDR, 0x31, (3 << 6));
	i2c_write(WM8960_DEVICE_ADDR, 0x33, 27);


	/*	设置ADC-DAC */
	i2c_write(WM8960_DEVICE_ADDR, 0x5, 0x0);

	/*	设置audio interface */
	i2c_write(WM8960_DEVICE_ADDR, 0x7, 0x2);

	/*	设置OUTPUTS */
	i2c_write(WM8960_DEVICE_ADDR, 0x2, (0xFF | 0x100));
	i2c_write(WM8960_DEVICE_ADDR, 0x3, (0xFF | 0x100));

	i2c_write(WM8960_DEVICE_ADDR, 0x28, (0xFF | 0x100));
	i2c_write(WM8960_DEVICE_ADDR, 0x29, (0xFF | 0x100));

	/*	设置DAC VOLUME */
	i2c_write(WM8960_DEVICE_ADDR, 0xa, (0xFF | 0x100));
	i2c_write(WM8960_DEVICE_ADDR, 0xb, (0xFF | 0x100));

	/*	设置mixer */
	i2c_write(WM8960_DEVICE_ADDR, 0x22, (1<<8));
	i2c_write(WM8960_DEVICE_ADDR, 0x25, (1<<8));
}
