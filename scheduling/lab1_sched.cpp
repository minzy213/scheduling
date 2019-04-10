/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id :
*	    Student name :
*
*   lab1_sched.c :
*       - Lab1 source file.
*       - Must contains scueduler algorithm function'definition.
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
using namespace std;

#include "lab1_sched_types.h"
#include "mlfq.h"
#include "lottery.h"
/*
* you need to implement FCFS, RR, MLFQ, Lottery or RM scheduler.
*/

void main()
{

	int m, n;	//for���� ���� ����
	int i = 0;		//� �˰����� ������ ������ ������ ����
	cout << "�˰����� �����ϼ���\n1 : FCFS\n2 : RR\n3 : MLFQ\n4 : Lottery\n=====================" << endl;
	cin >> i;
	if (i == 4) {	//lottery�϶��� ����ð�, �����ð� �ʿ� �����Ƿ� ���� ������
		lottery l;
		l.lotterymain();

	}
	/////////////////////////////////////

	

	else {	
		int jobc;	//job�� �� �� ������ ������ ����
		cout << "job�� ������ �Է��ϼ��� : ";
		cin >> jobc;//lotttery �̿��� ��쿡�� ����ð�, �����ð� �ʿ��ϴϱ� �Է¹޴´�
		//job���� ���� �ð��� ���� �ð��� �����ϱ� ���� �迭
		int** jobs = new int*[jobc];
		for (m = 0; m < jobc; m++) {
			jobs[m] = new int[2];
		}
		//job���� ���� �ð��� �����ð� �Է�
		for (m = 0; m < jobc; m++) {
			cout << m + 1 << "��° job�� �����ð��� �Է��ϼ��� : ";
			cin >> jobs[m][0];
			cout << m + 1 << "��° job�� ����ð��� �Է��ϼ��� : ";
			cin >> jobs[m][1];
		}

		//job�� �����ð� ������� ����
		int temp;
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
		}


		if (i == 3) {
			mlfq mlfq1 = { jobs, jobc };
			mlfq1.mlfqmain();
		}


	}

	
}