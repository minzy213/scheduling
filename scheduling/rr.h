#pragma once

#include "job.h"
#include "queue.h"
#include <stdlib.h>
#include <string.h>
#include <string>

class rr
{
public:
	rr(int** _jobs, int _jobc, int tq);
	~rr();

	void RR_job();
	///////////////
	int m, n;	//for���� ���� ����
	int** jobs;	//job���� ����ð�, �����ð� ������ �迭
	int jobc;	//job�� ���� ������ ����
	queue q;		//ť
public:
	int time;	// �� ����ð� ���ؼ� ��� ���μ��� ������ �ð� ���Ѵ�. ���� cpu�� ���� �ð��� ������ ++����
	int now;	// ���� �ð��� ��Ÿ����. �� �ʰ� �������� �˷���.
	int k;		//���° job���� ready ���°� �Ǿ����� Ȯ��
	int tq;
	void newjob();
	char name;
	string print;
};

