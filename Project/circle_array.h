#ifndef __CIRCLE_ARRAY_H
#define __CIRCLE_ARRAY_H
	
#include "stm32f4xx_conf.h"
int circle_read_index = 0;
int circle_write_index = 0;
int circle_array[6][200];
int target_pluse_num = 0;
int realtime_pluse_num = 0;
int serial_data_array[60];
int serial_data_index = 0;
u8 header_pre_find = 0;
u8 header_find = 0;
u8 end_pre_find = 0;
u8 end_find = 0;
void circle_array_read(int data);
#endif


