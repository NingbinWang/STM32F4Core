#include "app.h"

void app_init()
{
	printf("app_init\n");
	IMU_Init();
}

void app_update()
{
	//printf("app_update\n");
	IMU_Update();
}

void app_main()
{
	printf("app_main\n");
	ANO_Main();
}


void app_calangle()
{
	//printf("app_calangle\n");
}
