#include <iostream>
using namespace std;

class job
{
public:
	int arrtime;		//�����ð�
	int servtime;		//���� ����ð�
	job* next;
	int turnt;
	int respt;
	char name;
	job(int a, int s, char n);
	int priority;	//���° ť�� �ִ���
	job* getnext();
	void setnext(job* j);
	int play(int tq);
	job();
	~job();
};

