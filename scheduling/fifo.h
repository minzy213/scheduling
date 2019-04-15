#pragma once
#include "job.h"
#include <stdlib.h>
#include <string.h>
#include <string>
class fifo
{
public:
	int jobc;
	job *P;
	void FIFO_job();
	double cal_aturnt(int jobc, job *P);
	double cal_arespt(int jobc, job *P);
	fifo(int jobc, job *P);
	~fifo();
};

