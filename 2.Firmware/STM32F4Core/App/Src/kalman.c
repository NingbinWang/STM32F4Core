#include <math.h>
#include "kalman.h"



void Kalman1Creater(KALMAN_FILTER_T *pKalman,const float fLastP,const float fQ,const float fR)
{
	pKalman->LastP = fLastP;
	pKalman->Q = fQ;
	pKalman->R= fR;
}



void Kalman1Filter(KALMAN_FILTER_T *pKalman,const float input)
{
	pKalman->NowP = pKalman->LastP + pKalman->Q;
	pKalman->Kg = pKalman->NowP / (pKalman->NowP + pKalman->R);
	pKalman->out = pKalman->out + pKalman->Kg * (input - pKalman->out);
	pKalman->LastP = (1-pKalman->Kg) * pKalman->NowP ;
}
