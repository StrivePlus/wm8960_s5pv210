#define rVIC0IRQSTATUS 	0xF2000000
#define rVIC0ADDRESS	0xF2000F00

.text
.extern main
.extern uart_init
.global _start
_start:
	
	@使能IRQ中断
	mrs r1,cpsr			//r1=cpsr
	bic r1,#0x80		//r1&=~(1<<7)
	msr cpsr,r1			//cpsr=r1
	
	@安装处理IRQ异常的函数到0xD0037418地址处
	ldr r0,=HandlerIRQ
	ldr r1,=0xD0037418
	str r0,[r1]

	@uart_init();
	bl uart_init
	
	@main;
	bl main
	
halt:
	b halt 

	@while(1)

HandlerIRQ:
	
	@因为发生异常的时候，CPU自动将PC-4的值放到lr当中
	@while(1)
	sub lr,lr,#4

	@保护现场
	stmfd sp!,{r0-r12,lr}
	
	@设置恢复现场的地址给到lr，因为中断服务函数完成之后，会使用到lr寄存器
	ldr lr,=return_irq
	
	@判断中断源
	ldr r0,=rVIC0IRQSTATUS
	ldr r1,[r0]
	cmp r1,#0
	bne vic0_handler
	
	
	
	
return_irq:
	ldmfd sp!,{r0-r12,pc}^	//^，SPSR的值手动恢复到CPSR当中
	

vic0_handler:
	@获取当前有效的中断服务函数地址
	ldr r0,=rVIC0ADDRESS
	ldr pc,[r0]
		


		
	



.end

