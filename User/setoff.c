#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "IRSensor.h"
#include "Timer.h"
#include "Encoder.h"
#include "Control.h"
float ActualB1,ActualB2,TargetB,OutB;
float KpB,KiB,KdB;
float ErrorB0, ErrorB1, ErrorB2;
uint8_t S;
//还没调的：速度环pid,红外距离，pwm速度，pid与传感器比例暂时1：4，状态机还没写
void Setoff(void)
{
	Motor_Init();
	Timer1_Init();
	Encoder1_Init();
	Encoder2_Init();
	IRSensor_Init();
}

void TIM1_UP_IRQHandler(void)//5ms一次
{
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
	{
				control();//执行比例再调调目前想做成：传感器20ms，pid5ms可以在++，
				TargetB += Encoder2_Get();//状态机清零还没写 
				ActualB1 += Encoder1_Get();//直走才用pid
				ErrorB2 = ErrorB1;
				ErrorB1 = ErrorB0;
				ErrorB0 = TargetB - ActualB1;
				
				OutB += KpB * (ErrorB0 - ErrorB1) + KiB * ErrorB0
						+ KdB * (ErrorB0 - 2 * ErrorB1 + ErrorB2);
				
				if (OutB > 100) {OutB = 100;}
				if (OutB < -100) {OutB = -100;}
				MotorA_SetSpeed(OutB);
		
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	
	}

}