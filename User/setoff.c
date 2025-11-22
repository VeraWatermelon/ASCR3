#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "IRSensor.h"
#include "Timer.h"
#include "Encoder.h"
#include "Control.h"
void Setoff(void)
{
	Motor_Init();
	Timer1_Init();
	Encoder1_Init();
	Encoder2_Init();
	IRSensor_Init();
	while(1)
	{
	
	}
}

void TIM1_UP_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
	{
		control();//执行比例再调调
		
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	
	}

}