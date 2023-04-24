#ifndef _IMU_H_
#define _IMU_H_
#include "config.h"
#include "mpu6050.h"
#include "kalman.h"
#include "filter.h"
#include <stdio.h>

typedef struct GSENSOR_DATA_T{
	int16_t accX;
	int16_t accY;
	int16_t accZ;
	int16_t gyroX;
	int16_t gyroY;
	int16_t gyroZ;
}GSENSOR_DATA_T;

void IMU_Init();

void IMU_Update();

void IMU_GetData(GSENSOR_DATA_T* data);

#endif
