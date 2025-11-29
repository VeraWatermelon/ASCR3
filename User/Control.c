#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "IRSensor.h"
void control(void)
{
	uint8_t state,s=0,t=0;
	state=IRSensorL1_Get()|IRSensorL2_Get()|IRSensorR2_Get()|IRSensorR1_Get();
			switch (state)
			{
				case 0:		//1111或0000直走
					MotorA_SetSpeed(70);
					MotorB_SetSpeed(70);
				break;
				case 15:
					MotorA_SetSpeed(70);
					MotorB_SetSpeed(70);
				break;
				case 4: //0100左转
					MotorA_SetSpeed(60);
					MotorB_SetSpeed(85);
					s=1;
				break;
				case 2://0010右转
					MotorA_SetSpeed(85);
					MotorB_SetSpeed(60);
					t=1;
					break;
				case 8://1000猛左转
					if(s==0)
					{
					MotorA_SetSpeed(-55);
					MotorB_SetSpeed(96);
					}
					else
					{
					MotorA_SetSpeed(-60);
					MotorB_SetSpeed(97);
					s=0;
					}
					break;
				case 1://0001猛右转
					if(t==0)
					{
					MotorA_SetSpeed(96);
					MotorB_SetSpeed(-55);
					}
					else
					{
					MotorA_SetSpeed(97);
					MotorB_SetSpeed(-60);
					t=0; 
					}
					break;
				case 12://1100猛猛左转
					MotorA_SetSpeed(-55);
					MotorB_SetSpeed(100);
				break;
				case 3://0011猛猛右转
					MotorA_SetSpeed(100);
					MotorB_SetSpeed(-55);
				break;
				default:
				break;
			}	
}
