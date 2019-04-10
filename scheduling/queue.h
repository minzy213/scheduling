#pragma once
#include "job.h"

class queue
{
public:	
	job* tail;		//큐의 맨 마지막
	int tq;	//이 큐의 time quantum

	job* head;		//큐의 맨 처음
	int count = 0;
	queue();
	void push(job* j);
	job* pop();
	int play();
	void newpush(job *j);
	~queue();
};

