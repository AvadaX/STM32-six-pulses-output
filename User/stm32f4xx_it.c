/**
  ******************************************************************************
  * @file    GPIO/IOToggle/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    13-April-2012
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
#include "Gpio.h"
#include "stdlib.h"
#include "usart.h"
/** @addtogroup STM32F4xx_StdPeriph_Examples
  * @{
  */

/** @addtogroup IOToggle
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/
div_t division(int x, int y){
	div_t res;
	res.quot = x/y;
	res.rem = x%y;
	return res;
}
u32 time_index = 0;
int tunnel1[2];
int tunnel2[2];
int tunnel3[2];
int tunnel4[2];
int tunnel5[2];
int tunnel6[2];
int tunnel1_index = 0;
int tunnel2_index = 0;
int tunnel3_index = 0;
int tunnel4_index = 0;
int tunnel5_index = 0;
int tunnel6_index = 0;
int tunnel1_circle = 2000;
int tunnel2_circle = 2000;
int tunnel3_circle = 2000;
int tunnel4_circle = 2000;
int tunnel5_circle = 2000;
int tunnel6_circle = 2000;
div_t tunnel1_data;
div_t tunnel2_data;
div_t tunnel3_data;
div_t tunnel4_data;
div_t tunnel5_data;
div_t tunnel6_data;
int tunnel1_ex = 0;
int tunnel2_ex = 0;
int tunnel3_ex = 0;
int tunnel4_ex = 0;
int tunnel5_ex = 0;
int tunnel6_ex = 0;
int temp_save;
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //溢出中断
	{
		  if(!(time_index%tunnel1_circle)){
				 if(tunnel1_index == tunnel1_ex-2){
						tunnel1_circle = tunnel1_circle + 1;
				 }
				 if(tunnel1_index < tunnel1[0])	
						LED0 = !LED0;
				 else
					 LED6 = !LED6;
				 tunnel1_index ++;
			}
			if(!(time_index%tunnel2_circle)){
				 if(tunnel2_index == tunnel2_ex-2)
						tunnel2_circle = tunnel2_circle + 1;
				 if(tunnel2_index < tunnel2[0])
						LED1 = !LED1;
				 tunnel2_index ++; 
			}
			if(!(time_index%tunnel3_circle)){
				 if(tunnel3_index == tunnel3_ex-2)
						tunnel3_circle = tunnel3_circle + 1;
				 if(tunnel3_index < tunnel3[0])
						LED2 = !LED2;
				 tunnel3_index ++; 
			}
			if(!(time_index%tunnel4_circle)){
				 if(tunnel4_index == tunnel4_ex-2)
						tunnel4_circle = tunnel4_circle + 1;
				 if(tunnel4_index < tunnel4[0])
						LED3 = !LED3;
				 tunnel4_index ++;
			}
			if(!(time_index%tunnel5_circle)){
				 if(tunnel5_index == tunnel5_ex-2)
						tunnel5_circle = tunnel5_circle + 1;
				 if(tunnel5_index < tunnel5[0])
						LED4 = !LED4;
				 tunnel5_index ++;
			}
			if(!(time_index%tunnel6_circle)){
				 if(tunnel6_index == tunnel6_ex-2)
						tunnel6_circle = tunnel6_circle + 1;
				 if(tunnel6_index < tunnel6[0])
						LED5 = !LED5;
				 tunnel6_index ++;
			}
			time_index ++;
			//LED = !LED;
			if(time_index == 7999){
		//		LED6 = 1;
				temp_save = tunnel1_index;
				time_index = 0;  
			 /* tunnel1[0] = tunnel1[1]; 
				tunnel2[0] = tunnel2[1]; 
				tunnel3[0] = tunnel3[1]; 
				tunnel4[0] = tunnel4[1]; 
				tunnel5[0] = tunnel5[1]; 
				tunnel6[0] = tunnel6[1];*/
				tunnel1[0] = 8000; 
				tunnel2[0] = 8000; 
				tunnel3[0] = 8000; 
				tunnel4[0] = 8000; 
				tunnel5[0] = 8000; 
				tunnel6[0] = 8000;
				/*tunnel1_circle = 4000/tunnel1[0];
				tunnel2_circle = 4000/tunnel2[0];
				tunnel3_circle = 4000/tunnel3[0];
				tunnel4_circle = 4000/tunnel4[0];
				tunnel5_circle = 4000/tunnel5[0];
				tunnel6_circle = 4000/tunnel6[0];*/
				tunnel1_data= div(8000,tunnel1[0]);
				tunnel2_data= div(8000,tunnel2[0]);
				tunnel3_data= div(8000,tunnel3[0]);
				tunnel4_data= div(8000,tunnel4[0]);
				tunnel5_data= div(8000,tunnel5[0]);
				tunnel6_data= div(8000,tunnel6[0]);
				//LED = !LED;
				if(tunnel1_data.rem != 0){
				    tunnel1_circle = tunnel1_data.quot + 0;
					  tunnel1_ex = tunnel1[0] - tunnel1_data.rem;
						}
				else{
					  tunnel1_circle = tunnel1_data.quot;
					  tunnel1_ex = 0;
						}
				if(tunnel2_data.rem != 0){
				    tunnel2_circle = tunnel2_data.quot + 1;
						tunnel2_ex = tunnel2[0] - tunnel2_data.rem;
				}
				else{
					  tunnel2_circle = tunnel2_data.quot;
						tunnel2_ex = 0;
				}
				if(tunnel3_data.rem != 0){
				    tunnel3_circle = tunnel3_data.quot + 1;
						tunnel3_ex = tunnel3[0] - tunnel3_data.rem;
				}
				else{
					  tunnel3_circle = tunnel3_data.quot;
						tunnel3_ex = 0;
				}
				if(tunnel4_data.rem != 0){
				    tunnel4_circle = tunnel4_data.quot + 1;
						tunnel4_ex = tunnel4[0] - tunnel4_data.rem;
				}
				else{
					  tunnel4_circle = tunnel4_data.quot;
						tunnel4_ex = 0;
				}
				if(tunnel5_data.rem != 0){
				    tunnel5_circle = tunnel5_data.quot + 1;
						tunnel5_ex = tunnel5[0] - tunnel5_data.quot;
				}
				else{
					  tunnel5_circle = tunnel5_data.quot;
						tunnel5_ex = 0;
				}
				if(tunnel6_data.rem != 0){
				    tunnel6_circle = tunnel6_data.quot + 1;
						tunnel6_ex = tunnel6[0] - tunnel6_data.rem;
				}
				else{
					  tunnel6_circle = tunnel6_data.quot;
						tunnel6_ex = 0;
				}
        tunnel1_index = 0;	
				tunnel2_index = 0;
				tunnel3_index = 0;	
				tunnel4_index = 0;	
				tunnel5_index = 0;	
				tunnel6_index = 0;
				
			}		
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除中断标志位
}





u8 Res;
void USART1_IRQHandler(void)                	//串口1中断服务程序
{
	
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	{
		Res =USART_ReceiveData(USART1);//(USART1->DR);	//读取接收到的数据
		Res = Res;  		 
  } 
} 


/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
