/*
 * main.c
 *
 *  Created on: Mar 3, 2017
 *      Author: striveplus
 */
#include "stdio.h"
#include "s5pv210.h"
#include "audio.h"

int main(void)
{
	printf("Audio Test\r\n");

	int offset = 0x38;				// 音频数据开始的地方 @需要深究,可能可以便宜与发多少个字节有关
	//int offset = 0x00;
	short *p = (short *)0x42000000;	// 音频文件应该位于的位置
	i2c_init();						// 初始化i2c
	vm8960_init();					// 初始化wm8960
	i2s_init();						// 初始化i2s
	//循环播放音频文件
	while(1)
	{
		// ppolling Primary Tx FIFO0 full status indication
		while((IISCON & (1 << 8)) == (1 << 8));
		IISTXD = *(p + offset);		//每次发送2字节
		offset++;
		if(offset > (22827086 - 0x38) / 2)	//有多少个2字节 = （文件大小 - 偏移）/ 2 @需要深究
		offset = 0x38;
	}
	return 0;

}

