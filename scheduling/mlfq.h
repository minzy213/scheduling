#pragma once
#include "queue.h"
#include "string"
class mlfq
{
	int m, n;	//for���� ���� ����
	int** jobs;	//job���� ����ð�, �����ð� ������ �迭
	int jobc;	//job�� ���� ������ ����
	queue q0;
	queue q1;
	queue q2;
public:
	int time = 0;	// �� ����ð� ���ؼ� ��� ���μ��� ������ �ð� ���Ѵ�. ���� cpu�� ���� �ð��� ������ ++����
	int now = 0;	// ���� �ð��� ��Ÿ����. �� �ʰ� �������� �˷���.
	int k = 0;		//���° job���� ready ���°� �Ǿ����� Ȯ��

	mlfq(int** _jobs, int _jobc);
	~mlfq();
	void newjob();
	void priomin(job* j);
	void mlfqmain();
	char name = 'A';
	string print = "|";
};

