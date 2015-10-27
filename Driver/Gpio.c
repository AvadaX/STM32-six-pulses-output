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

Gpio_Info Gpio_info[LED_NUMBER]={
    {LED1_RCC,LED1_GPIO,LED1_GPIO_PIN},
    {LED2_RCC,LED2_GPIO,LED2_GPIO_PIN},
    {LED3_RCC,LED3_GPIO,LED3_GPIO_PIN},
    {LED4_RCC,LED4_GPIO,LED4_GPIO_PIN}
};
/********************************************************************************************
*函数名称：void LEDGpio_Init(void)
*
*入口参数：无
*
*出口参数：无
*
*功能说明：LED初始化
*******************************************************************************************/
void LEDGpio_Init(void)
{
    uint8_t i;
    GPIO_InitTypeDef  GPIO_InitStructure;

		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOD , ENABLE);//使能GPIOF时钟

		//GPIOF9,F10初始化设置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
		GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
		GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化
		
		GPIO_SetBits(GPIOC,GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
		GPIO_SetBits(GPIOD,GPIO_Pin_12);
}

void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}



