#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Key.h"

int main(void)
{
	OLED_Init();
	Key_Init();
	while (1)
	{
		if(Key_GetNum()==1)
		{
			
		}
	}
}
