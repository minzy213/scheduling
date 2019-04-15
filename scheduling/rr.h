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
	int m, n;	//for문을 위한 변수
	int** jobs;	//job들의 수행시간, 도착시간 저장한 배열
	int jobc;	//job의 갯수 저장한 변수
	queue q;		//큐
public:
	int time;	// 총 예상시간 더해서 모든 프로세스 끝나는 시간 구한다. 만약 cpu가 쉬는 시간이 나오면 ++해줌
	int now;	// 지금 시간을 나타낸다. 몇 초가 지났는지 알려줌.
	int k;		//몇번째 job까지 ready 상태가 되었는지 확인
	int tq;
	void newjob();
	char name;
	string print;
};

