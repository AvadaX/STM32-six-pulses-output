#include "circle_array.h"


int circle_array_get(int* array_data){
		
}

void circle_array_read(int data){
	 int data_correct = 1;
	 int temp_xor;
	 int i;
   if(!header_pre_find && data == 0xFF){
			header_pre_find = 1;
	 }
	 else if(header_pre_find && !header_find){
			if(data == 0xFF){
					header_find = 1;
				  serial_data_index = 0;
			}
			else{
					header_pre_find = 0;
			}
	 }
	 else if(header_find){
			serial_data_array[serial_data_index] = data;
		  serial_data_index ++;
		  if(serial_data_index > 50){
					serial_data_index = 0;
			}
		  if(serial_data_index == 17){
						if(serial_data_array[serial_data_index - 1] == 0xEE && serial_data_array[serial_data_index -2] == 0xee){
								temp_xor = serial_data_array[2]^serial_data_array[3]^serial_data_array[4]^serial_data_array[5]^serial_data_array[6]^  \
													 serial_data_array[7]^serial_data_array[8]^serial_data_array[9]^serial_data_array[10]^serial_data_array[11]^ \
													 serial_data_array[12]^serial_data_array[13]^serial_data_array[0]^serial_data_array[1];							
								if(temp_xor == serial_data_array[14]){
										for(i = 0; i<15; i++){
											if(serial_data_array[i] > 0xff)
												data_correct = 0;
											else
												data_correct = 1;
										}
										if(data_correct){											
											array_deal(serial_data_array[2],serial_data_array[3],serial_data_array[5],serial_data_array[7], \
																 serial_data_array[9],serial_data_array[11],serial_data_array[13],serial_data_array[15]);
										}
								}
										
						}
						header_pre_find = 0;
						header_find = 0;
			}

	 }
}

int array_deal(int time_index_h,int time_index_l,int tunnel1_data,int tunnel2_data,int tunnel3_data,int tunnel4_data,int tunnel5_data,int tunnel6_data){
	
}
