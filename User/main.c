/****************************************Copyright (c)***************************************
**                                 http://www.52pi.net/
**-------------------------------------------------------------------------------------------
** File name:           main.c
** Last modified Date:  2014-02-28
** Last Version:        V1.0
** Descriptions:        SOM407�װ� LED����
**
**-------------------------------------------------------------------------------------------
** Created by:          ����
** Last modified Date:  2014-02-28
** Last Version:        V1.00
** Descriptions:        SOM407�װ� LED����
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
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
  LEDGpio_Init();                  //LED���ų�ʼ��
  TIM3_Int_Init(5-1,84-1);//��ʱ��ʱ��84M����Ƶϵ��84������84M/84=1000Khz�ļ���Ƶ�ʣ�����5��Ϊ5us  
	LED = 0;
	uart_init(115200);
  while (1)
  {

     /* LED4_ONOFF(Bit_SET);         //LED4�øߣ���ƣ� ��ԭ��ͼ���Կ�����LEDΪ�͵�ƽ����
      LED1_ONOFF(Bit_RESET);       //LED1�õͣ����ƣ�
      Delay(5000000);             //��ʱ
      LED1_ONOFF(Bit_SET);         //����ͬ��ע��
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
*�������ƣ�void Delay(__IO uint32_t nCount)
*
*��ڲ�������
*
*���ڲ�������
*
*����˵������ʱ����
*******************************************************************************************/

void TIM3_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  ///ʹ��TIM3ʱ��
	
  TIM_TimeBaseInitStructure.TIM_Period = arr; 	//�Զ���װ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);//��ʼ��TIM3
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //����ʱ��3�����ж�
	TIM_Cmd(TIM3,ENABLE); //ʹ�ܶ�ʱ��3
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; //��ʱ��3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //��ռ���ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
}

