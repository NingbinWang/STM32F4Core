#include "imu.h"

void IMU_Init()
{
	MPU6050_Init(&mpu6050i2cbus);
}


void IMU_Update()
{
	MPU6050_t imudata;
	unsigned int i = 0;
	KALMAN_FILTER_T imukalman={0};
	FIRSTORDERFILTER_T imufilter = {0};
	MPU6050_Read_Accel(&mpu6050i2cbus,&imudata);
	Kalman1Creater(&imukalman,0.02,0.001,0.543);//lastP = 0.02,Q=0.01,R=0.543
	for(i = 0;i<3;i++)
	{
	  Kalman1Filter(&imukalman,imudata.Ax);
	  imudata.Ax = imukalman.out;
	  Kalman1Filter(&imukalman,imudata.Ay);
	  imudata.Ay = imukalman.out;
	  Kalman1Filter(&imukalman,imudata.Az);
	  imudata.Az = imukalman.out;
	}
	MPU6050_Read_Gyro(&mpu6050i2cbus,&imudata);
	imufilter.falpha = 0.25f;
	for(i = 0;i<3;i++)
	{
		imudata.Gx = (double)filter_firstorderlowpass(&imufilter,(float)imudata.Gx);
		imudata.Gy = (double)filter_firstorderlowpass(&imufilter,(float)imudata.Gy);
		imudata.Gz = (double)filter_firstorderlowpass(&imufilter,(float)imudata.Gz);
	}

}
