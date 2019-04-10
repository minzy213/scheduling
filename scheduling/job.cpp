#include "job.h"



job::job(int a, int s, char n)
{
	arrtime = a;
	servtime = s;
	next = NULL;
	name = n;
}

job* job::getnext()		
{

	return next;
}
void job::setnext(job* j)
{
	next = j;
}

int job::play(int tq) {
	if (servtime < tq) tq = servtime;
	servtime = servtime - tq;
	return tq;
}

job::~job()
{
}
