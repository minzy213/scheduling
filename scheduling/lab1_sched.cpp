/*
*   DKU Operating System Lab
*       Lab1 (Scheduler Algorithm Simulator)
*       Student id :
*       Student name :
*
*   lab1_sched.c :
*       - Lab1 source file.
*       - Must contains scueduler algorithm function'definition.
*
*/

#include "lab1_sched_types.h"
/*
* you need to implement FCFS, RR, MLFQ, Lottery or RM scheduler.
*/

void main()
{

	int jobc;   //job�� �� �� ������ ������ ����
	int m, n;   //for���� ���� ����
	int tq;      //rr�� tq�� ���� ����
	int i = 0;      //� �˰����� ������ ������ ������ ����
	cout << "�˰����� �����ϼ���\n1 : FCFS\n2 : RR\n3 : MLFQ\n4 : Lottery\n=====================" << endl;
	cin >> i;


	/* 4) Lottery �˰��� */
	if (i == 4) {         //lottery�϶��� ����ð�, �����ð� �ʿ� �����Ƿ� ���� ������
		lottery l;         //lottery ����
		l.lotterymain();

	}
	/////////////////////////////////////

	else if (i == 1) {


		cout << "job�� ������ �Է��ϼ��� : ";
		cin >> jobc;

		job S;
		job *P = new job[jobc];
		memcpy(P, &S, sizeof(job));


		char k = 'A';
		for (m = 0; m < jobc; m++)
		{
			cout << m + 1 << "��° job�� ���� �ð�, ���� �ð� �Է�>> \n";
			P[m].name = k;
			k++;
			cin >> P[m].arrtime >> P[m].servtime;
		}

		/* 1) FIFO �˰��� */
		fifo f ( jobc, P );
		f.FIFO_job();
	}




	else if (i == 3 || i == 2) {
		cout << "job�� ������ �Է��ϼ��� : ";
		cin >> jobc;//lotttery �̿��� ��쿡�� ����ð�, �����ð� �ʿ��ϴϱ� �Է¹޴´�

		int** jobs = new int*[jobc];      //job���� ���� �ð��� ���� �ð��� �����ϱ� ���� �迭
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
		/* 3) MLFQ �˰��� */
		if (i == 3) {
			mlfq mlfq1 ( jobs, jobc );
			mlfq1.mlfqmain();
		}
		/* 2) RR �˰��� */
		else if (i == 2) {
			cout << "\ntime quantum >> ";   cin >> tq;
			rr r ( jobs, jobc, tq );
			r.RR_job();
		}

	}
	else {
		cout << "�Է��� ���ڰ� Ʋ���ϴ�! ";


	}
}
