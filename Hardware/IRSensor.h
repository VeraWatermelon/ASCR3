#ifndef __IRSENSOR_H
#define __IRSENSOR_H

void IRSensor_Init(void);
uint8_t IRSensorL1_Get(void);
uint8_t IRSensorL2_Get(void);
uint8_t IRSensorR2_Get(void);
uint8_t IRSensorR1_Get(void);

#endif
