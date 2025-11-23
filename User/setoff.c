#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "IRSensor.h"
#include "Timer.h"
#include "Control.h"
void Setoff(void)
{
	Motor_Init();
	Timer1_Init();
	IRSensor_Init();
	while(1)
	{}
}

void TIM1_UP_IRQHandler(void)//5ms一次
{
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
	{
				control();
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	}

}