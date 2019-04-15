#include "fifo.h"



fifo::fifo(int _jobc, job *_P)
{
	jobc = _jobc;
	P = _P;
}


fifo::~fifo()
{
}

void fifo::FIFO_job()
{
	int i, j;   int tempt = 0, sumt = 0;
	double aturnt = 0, arespt = 0;

	aturnt = cal_aturnt(jobc, P);
	arespt = cal_arespt(jobc, P);

	cout << "\n결과: " << endl;
	cout << "프로세스명\tTurnaround Time\tResponse Time" << endl;
	for (i = 0; i < jobc; i++)
	{
		cout << P[i].name << "\t\t" << P[i].turnt << "\t\t" << P[i].respt << endl;
	}

	cout << "평균 turnaround time: " << aturnt << "      평균 response time: " << arespt << endl;
	cout << "\n\n출력: ";
	for (i = 0; i < jobc; i++)
	{
		for (j = 0; j < P[i].servtime; j++)
			cout << "|" << P[i].name;

		if (i == jobc - 1)
			cout << "|";
	}
	cout << "\n";
}

double fifo::cal_aturnt(int jobc, job *P)
{
	int i, tempt = 0, sumt = 0;   double avg_turnt = 0;
	for (i = 0; i < jobc; i++)
	{
		tempt += P[i].servtime;
		P[i].turnt = tempt - P[i].arrtime;
		sumt += P[i].turnt;
	}
	avg_turnt = (double)sumt / jobc;
	return avg_turnt;
}

double fifo::cal_arespt(int jobc, job *P)
{
	int i, tempt = 0, sumt = 0;   double avg_respt = 0;
	P[0].respt = 0;
	for (i = 1; i < jobc; i++)
	{
		P[i].respt = P[i].turnt = P[i].servtime;
		sumt += P[i].respt;
	}
	avg_respt = (double)sumt / i;
	return avg_respt;
}
