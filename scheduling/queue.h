#pragma once
#include "job.h"

class queue
{
public:	
	job* tail;		//ť�� �� ������
	int tq;	//�� ť�� time quantum

	job* head;		//ť�� �� ó��
	int count = 0;
	queue();
	void push(job* j);
	job* pop();
	int play();
	void newpush(job *j);
	~queue();
};

