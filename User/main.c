/****************************************Copyright (c)***************************************
**                                 http://www.52pi.net/
**-------------------------------------------------------------------------------------------
** File name:           main.c
** Last modified Date:  2014-02-28
** Last Version:        V1.0
** Descriptions:        SOM407底板 LED测试
**
**-------------------------------------------------------------------------------------------
** Created by:          飞翔
** Last modified Date:  2014-02-28
** Last Version:        V1.00
** Descriptions:        SOM407底板 LED测试
**
**-------------------------------------------------------------------------------------------
** Modified by:         
** Modified date:       
** Version:             
** Descriptions:        
**-------------------------------------------------------------------------------------------
********************************************************************************************/
#include "stm32f4xx.h"
#include "Gpio.h"
#include "usart.h"

void TIM3_Int_Init(u16 arr,u16 psc);

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
  LEDGpio_Init();                  //LED引脚初始化
  TIM3_Int_Init(5-1,84-1);//定时器时钟84M，分频系数84，所以84M/84=1000Khz的计数频率，计数5次为5us  
	LED = 0;
	uart_init(115200);
  while (1)
  {

     /* LED4_ONOFF(Bit_SET);         //LED4置高（灭灯） 从原理图可以看出，LED为低电平亮。
      LED1_ONOFF(Bit_RESET);       //LED1置低（开灯）
      Delay(5000000);             //延时
      LED1_ONOFF(Bit_SET);         //以下同上注视
      LED2_ONOFF(Bit_RESET);
      Delay(5000000);
      LED2_ONOFF(Bit_SET);
      LED3_ONOFF(Bit_RESET);
      Delay(5000000);
      LED3_ONOFF(Bit_SET);
      LED4_ONOFF(Bit_RESET);
      Delay(50000000);*/
  }
}
/********************************************************************************************
*函数名称：void Delay(__IO uint32_t nCount)
*
*入口参数：无
*
*出口参数：无
*
*功能说明：延时函数
*******************************************************************************************/

void TIM3_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  ///使能TIM3时钟
	
  TIM_TimeBaseInitStructure.TIM_Period = arr; 	//自动重装载值
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);//初始化TIM3
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //允许定时器3更新中断
	TIM_Cmd(TIM3,ENABLE); //使能定时器3
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; //定时器3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
}

