#include "ANO_DT.h"


static void ANTO_Send(const ANTO_MODE_E mode)
{
	uint8_t i;
	uint8_t len=2;
	int16_t Anto[12];
	GSENSOR_DATA_T gsensordata;
	int8_t *pt = (int8_t*)(Anto);

	switch(mode){
		case ANTO_MPU_MAGIC:
			IMU_GetData(&gsensordata);
		    memcpy(&Anto[2],(int8_t*)&gsensordata,sizeof(GSENSOR_DATA_T));//六轴传感器
		    Anto[8] = 0;
		    Anto[9] = 0;
		    Anto[10] = 0;
		    //			memcpy(&Anto[8],(int8_t*)&AK8975,sizeof(_st_Mag));//未使用到磁力计
		    len = 18;
		break;
	}
	Anto[0] = 0XAAAA;
	Anto[1] = len | mode<<8;
	pt[len+4] = (int8_t)(0xAA+0xAA);
	for(i=2;i<len+4;i+=2)    //a swap with b;
	{
		pt[i] ^= pt[i+1];
		pt[i+1] ^= pt[i];
		pt[i] ^= pt[i+1];
		pt[len+4] += pt[i] + pt[i+1];
	}
	HAL_UART_Transmit(&ANODTuartbus,(uint8_t *)pt,len+5,500);
}


void ANO_Main()
{
	ANTO_Send(ANTO_MPU_MAGIC);
}
