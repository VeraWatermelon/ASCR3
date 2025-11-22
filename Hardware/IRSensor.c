#include "stm32f10x.h"                  // Device header

void IRSensor_Init(void)				//红外传感器初始化
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	//上拉输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5| GPIO_Pin_10| GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

uint8_t IRSensorL1_Get(void)//检测红外左一
{
	return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4);//看接线来改改引脚对应关系
}

uint8_t IRSensorL2_Get(void)//左二
{
	return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5);
}

uint8_t IRSensorR2_Get(void)//右二（中间的）
{
	return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10);
}

uint8_t IRSensorR1_Get(void)//右一
{
	return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11);
}
	
	
