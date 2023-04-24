#include "imu.h"
#include <string.h>

MPU6050_t mpu6050;

void IMU_Init()
{
	MPU6050_Init(&mpu6050i2cbus);
	memset(&mpu6050,0,sizeof(MPU6050_t));
}


void IMU_Update()
{
	MPU6050_Read_Accel(&mpu6050i2cbus,&mpu6050);
	MPU6050_Read_Gyro(&mpu6050i2cbus,&mpu6050);
}

void IMU_GetData(GSENSOR_DATA_T* data)
{
    data->accX=mpu6050.Accel_X_RAW;
    data->accY=mpu6050.Accel_Y_RAW;
    data->accZ=mpu6050.Accel_Z_RAW;
    data->gyroX=mpu6050.Gyro_X_RAW;
    data->gyroY=mpu6050.Gyro_Y_RAW;
    data->gyroZ=mpu6050.Gyro_Z_RAW;
}
