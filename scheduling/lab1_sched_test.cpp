/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id :
*	    Student name :
*
*   lab1_sched.c :
*       - Lab1 source file.
*       - Must contains scueduler algorithm test code.
*
*/
#include <iostream>
//#include <aio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
//#include <sys/time.h>
#include <string.h>
//#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
//#include <pthread.h>
//#include <asm/unistd.h>

#include "lab1_sched_types.h"
using namespace std;

/*
* you need to implement scheduler simlator test code.
*
*/

//int main(int argc, char *argv[]) {

//}
/////////////////////////////////////////////////////////



void main()
{

	int jobc;	//job�� �� �� ������ ������ ����
	int m, n;	//for���� ���� ����
	int tq;		//rr�� tq�� ���� ����
	int i = 0;		//� �˰����� ������ ������ ������ ����
	//cout << "�˰����� �����ϼ���\n1 : FCFS\n2 : RR\n3 : MLFQ\n4 : Lottery\n=====================" << endl;
	//cin >> i;




	/////////////////////////////////////



	cout << "job�� ������ �Է��ϼ��� : ";
	cin >> jobc;

	job S;
	job *P = new job[jobc];
	memcpy(P, &S, sizeof(job));


	int** jobs = new int*[jobc];		//job���� ���� �ð��� ���� �ð��� �����ϱ� ���� �迭
	for (m = 0; m < jobc; m++) {
		jobs[m] = new int[2];
	}

	char k = 'A';
	for (m = 0; m < jobc; m++)
	{
		cout << m + 1 << "��° job�� ���� �ð�, ���� �ð� �Է�>> \n";
		P[m].name = k;
		k++;
		cin >> P[m].arrtime >> P[m].servtime;
		jobs[m][0] = P[m].arrtime;
		jobs[m][1] = P[m].servtime;
	}



	//job���� ���� �ð��� �����ð� �Է�
/*	for (m = 0; m < jobc; m++) {
		cout << m + 1 << "��° job�� �����ð��� �Է��ϼ��� : ";
		cin >> jobs[m][0];
		cout << m + 1 << "��° job�� ����ð��� �Է��ϼ��� : ";
		cin >> jobs[m][1];
	}
	*/
	//job�� �����ð� ������� ����
/*	int temp;
	for (m = 0; m < jobc; m++) {
		for (n = m + 1; n < jobc; n++) {
			if (jobs[m][0] > jobs[n][0]) {
				//job�� �����ð� �ٲٱ�
				temp = jobs[m][0];
				jobs[m][0] = jobs[n][0];
				jobs[n][0] = temp;

				//job�� ����ð� �ٲٱ�
				temp = jobs[m][1];
				jobs[m][1] = jobs[n][1];
				jobs[n][1] = temp;
			}
		}

	}*/
	
	/* 1) FIFO �˰��� */
	fifo f = { jobc, P };
	f.FIFO_job();

	/* 2) RR �˰��� */
	cout << "\ntime quantum : 1\n";
		rr r1 = { jobs, jobc, 1 };
		r1.RR_job();

		cout << "\ntime quantum : 2\n";
		rr r2 = { jobs, jobc, 2 };
		r2.RR_job();

		cout << "\ntime quantum : 4\n";
		rr r = { jobs, jobc, 4 };
		r.RR_job();
	
	/* 3) MLFQ �˰��� */
		mlfq mlfq1 = { jobs, jobc };
		mlfq1.mlfqmain();

	/* 4) Lottery �˰��� */
	lottery l;			//lottery ����
	l.lotterymain();
	cout << "�Է��� ���ڰ� Ʋ���ϴ�! ";


}
