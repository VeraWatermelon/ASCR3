#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "IRSensor.h"
void control(void)//先随便写个数，之后再慢慢调/红外的01可能也是反的
{
	uint8_t state;
	state=IRSensorL1_Get()|IRSensorL2_Get()|IRSensorR2_Get()|IRSensorR1_Get();
			switch (state)
			{
				case 0:		//1111或0000直走
					MotorA_SetSpeed(10);
					MotorB_SetSpeed(10);
				break;
				case 15:
					MotorA_SetSpeed(10);
					MotorB_SetSpeed(10);
				break;
				case 4: //0100左转
					MotorA_SetSpeed(20);
					MotorB_SetSpeed(30);
				break;
				case 2://0010右转
					MotorA_SetSpeed(30);
					MotorB_SetSpeed(20);
					break;
				case 8://1000猛左转
					MotorA_SetSpeed(10);
					MotorB_SetSpeed(20);
					break;
				case 1://0001猛右转
					MotorA_SetSpeed(20);
					MotorB_SetSpeed(10);
					break;
				case 12://1100猛猛左转
					MotorA_SetSpeed(0);
					MotorB_SetSpeed(40);
				break;
				case 3://0011猛猛右转
					MotorA_SetSpeed(40);
					MotorB_SetSpeed(0);
				break;
				default:
				break;
			}	
}
