#ifndef _FILTER_H_
#define _FILTER_H_

#include <math.h>
#define Pi 3.141592

typedef struct {
	float fFs;//截止频率
	float fTs;//采样周期
	float falpha;//滤波系数
}FIRSTORDERFILTER_T;

void filter_firstorderlowpass_creater(FIRSTORDERFILTER_T *pstFilter,  const float Fc,const float Ts);


float filter_firstorderlowpass(FIRSTORDERFILTER_T *pstFilter,const float value);

#endif
