#pragma once
#include "queue.h"
#include "string"
class mlfq
{
	int m, n;	//for���� ���� ����
	int** jobs;	//job���� ����ð�, �����ð� ������ �迭
	int jobc;	//job�� ���� ������ ����
	queue q0;		//�켱������ ���� ���� ť
	queue q1;		//�켱������ �ι�°�� ���� ť
	queue q2;		//�켱������ ���� ���� ť
public:
	int time = 0;	// �� ����ð� ���ؼ� ��� ���μ��� ������ �ð� ���Ѵ�. ���� cpu�� ���� �ð��� ������ ++����
	int now = 0;	// ���� �ð��� ��Ÿ����. �� �ʰ� �������� �˷���.
	int k = 0;		//���° job���� ready ���°� �Ǿ����� Ȯ��

	mlfq(int** _jobs, int _jobc);
	~mlfq();
	void newjob();
	void mlfqmain();
	char name = 'A';
	string print = "|";
};

