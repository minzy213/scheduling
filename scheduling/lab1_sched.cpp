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

	int m, n;	//for문을 위한 변수
	int i = 0;		//어떤 알고리즘을 선택할 것인지 저장할 변수
	cout << "알고리즘을 선택하세요\n1 : FCFS\n2 : RR\n3 : MLFQ\n4 : Lottery\n=====================" << endl;
	cin >> i;
	if (i == 4) {	//lottery일때는 수행시간, 도착시간 필요 없으므로 따로 돌린다
		lottery l;
		l.lotterymain();

	}
	/////////////////////////////////////

	

	else {	
		int jobc;	//job이 총 몇 개인지 저장할 변수
		cout << "job의 갯수를 입력하세요 : ";
		cin >> jobc;//lotttery 이외의 경우에는 수행시간, 도착시간 필요하니까 입력받는다
		//job들의 수행 시간과 도착 시간을 저장하기 위한 배열
		int** jobs = new int*[jobc];
		for (m = 0; m < jobc; m++) {
			jobs[m] = new int[2];
		}
		//job들의 수행 시간과 도착시간 입력
		for (m = 0; m < jobc; m++) {
			cout << m + 1 << "번째 job의 도착시간을 입력하세요 : ";
			cin >> jobs[m][0];
			cout << m + 1 << "번째 job의 수행시간을 입력하세요 : ";
			cin >> jobs[m][1];
		}

		//job의 도착시간 순서대로 정렬
		int temp;
		for (m = 0; m < jobc; m++) {
			for (n = m + 1; n < jobc; n++) {
				if (jobs[m][0] > jobs[n][0]) {
					//job의 도착시간 바꾸기
					temp = jobs[m][0];
					jobs[m][0] = jobs[n][0];
					jobs[n][0] = temp;

					//job의 수행시간 바꾸기
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