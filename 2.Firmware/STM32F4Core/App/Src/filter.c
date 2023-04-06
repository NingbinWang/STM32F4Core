#include "filter.h"


void filter_firstorderlowpass_creater(FIRSTORDERFILTER_T *pstFilter,  const float Fc,const float Ts)
{
  float ftmp = 0;
  ftmp=2.0 * (Pi) * Fc * Ts;
  pstFilter->falpha = ftmp/(ftmp+1);
}

//一阶低通滤波
float filter_firstorderlowpass(FIRSTORDERFILTER_T *pstFilter,const float value)
{
	static float fOut_last=0;
	float fOutvalue = 0;
	static char cFirst_flag=1;
	//如果视记录为第一次进入，则给out_last直接赋值
	if(cFirst_flag == 1)
	{
		cFirst_flag = 0;
		fOut_last = value;
	}
	fOutvalue = fOut_last+(pstFilter->falpha)*(value-fOut_last);
	fOut_last = fOutvalue;
	return fOutvalue;
}
