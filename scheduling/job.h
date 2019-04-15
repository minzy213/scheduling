#include <iostream>
using namespace std;

class job
{
public:
	int arrtime;		//도착시간
	int servtime;		//예상 실행시간
	job* next;
	int turnt;
	int respt;
	char name;
	job(int a, int s, char n);
	int priority;	//몇번째 큐에 있는지
	job* getnext();
	void setnext(job* j);
	int play(int tq);
	job();
	~job();
};

