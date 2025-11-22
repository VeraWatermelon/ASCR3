#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "IRSensor.h"
void Setoff(void)
{
	IRSensor_Init();
	Motor_Init();
	while(1)
	{
	
	}
}
