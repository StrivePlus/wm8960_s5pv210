/*
 * audio.h
 *
 *  Created on: Mar 6, 2017
 *      Author: striveplus
 */

#ifndef INCLUDE_AUDIO_H_
#define INCLUDE_AUDIO_H_

void i2s_init(void);
void i2c_init(void);
void i2c_write(int slave_addr, int addr, int data);
void vm8960_init(void);


#endif /* INCLUDE_AUDIO_H_ */
