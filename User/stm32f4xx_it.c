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
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //溢出中断
	{
		  /*LED4_ONOFF(Bit_SET);         //LED4置高（灭灯） 从原理图可以看出，LED为低电平亮。
      LED1_ONOFF(Bit_RESET);       //LED1置低（开灯）     
      LED2_ONOFF(Bit_SET);
      LED3_ONOFF(Bit_RESET);*/
		  LED0 = !LED0;
			LED1 = !LED1;
			LED2 = !LED2;
			LED3 = !LED3;
		  if(!(time_index%tunnel1[0])){
				 if(tunnel1_index < tunnel1[0]){
						LED0 = !LED0;
						tunnel1_index ++;
				 }									 
			}
			if(!(time_index%tunnel2[0])){
				 if(tunnel2_index < tunnel2[0]){
						LED1 = !LED1;
						tunnel2_index ++;
				 } 
			}
			if(!(time_index%tunnel3[0])){
				 if(tunnel3_index < tunnel3[0]){
						LED2 = !LED2;
						tunnel3_index ++;
				 } 
			}
			if(!(time_index%tunnel4[0])){
				 if(tunnel4_index < tunnel4[0]){
						LED3 = !LED3;
						tunnel4_index ++;
				 }
			}
			if(!(time_index%tunnel5[0])){
				 if(tunnel5_index < tunnel5[0]){
						LED4 = !LED4;
						tunnel5_index ++;
				 }
			}
			if(!(time_index%tunnel6[0])){
				 if(tunnel6_index < tunnel6[0]){
						LED5 = !LED5;
						tunnel6_index ++;
				 }
			}
			time_index ++;
			if(time_index == 1000){
				time_index = 0;  
			 /* tunnel1[0] = tunnel1[1]; 
				tunnel2[0] = tunnel2[1]; 
				tunnel3[0] = tunnel3[1]; 
				tunnel4[0] = tunnel4[1]; 
				tunnel5[0] = tunnel5[1]; 
				tunnel6[0] = tunnel6[1];*/
				tunnel1[0] = 1; 
				tunnel2[0] = 1; 
				tunnel3[0] = 1; 
				tunnel4[0] = 1; 
				tunnel5[0] = 1; 
				tunnel6[0] = 1;
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
