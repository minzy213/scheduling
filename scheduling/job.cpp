#include "job.h"


job::job() {

}
job::job(int a, int s, char n)
{		//job�� ������. 
	arrtime = a;
	servtime = s;
	next = NULL;
	name = n;
}

job* job::getnext()		//ť�� ���� ��Ҹ� �������� ���� �޼���
{						//this�� ������ ��Ҷ�� next�� null
	return next;
}

void job::setnext(job* j)	//ť�� ���� ��Ҹ� next�� ����
{
	next = j;
}

int job::play(int tq) {		//job�� ����Ǵ°�. tq�� �Է¹޾Ƽ� 
	if (servtime < tq) tq = servtime;	//���� �����ִ� servtime�� tq���� ������ �׸�ŭ�� ����.
	servtime = servtime - tq;			//���� �����ִ� servtime�� tq���� ũ�ٸ� tq��ŭ�� ����.
	return tq;							//�󸶳� �����ߴ��� �������ش�
}

job::~job()
{
}
