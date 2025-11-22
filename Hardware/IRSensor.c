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
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4)==1)
	{return 0x01;}
	else 
	{return 0x00;}	//看接线来改改引脚对应关系
}

uint8_t IRSensorL2_Get(void)//左二
{
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)==1)
	{return 0x02;}
	else 
	{return 0x00;}
}

uint8_t IRSensorR2_Get(void)//右二（中间的）
{
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10)==1)
	{return 0x04;}
	else 
	{return 0x00;}
}

uint8_t IRSensorR1_Get(void)//右一
{
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)==1)
	{return 0x08;}
	else 
	{return 0x00;}
}
	
	
