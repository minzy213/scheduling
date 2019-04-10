#include "mlfq.h"



mlfq::mlfq(int** _jobs, int _jobc)
{
	jobs = _jobs;
	jobc = _jobc;
	for (m = 0; m < jobc; m++) {
		time = time + jobs[m][0];
	}
}

void mlfq::newjob()
{
	if (jobs[k][0] <= now) {
		q0.newpush(new job(jobs[k][0], jobs[k][1], name));
		
		k++;
		name++;
	}
}
void mlfq::priomin(job* j)
{

}
void mlfq::mlfqmain()
{
	q0.tq = 1;
	q1.tq = 2;
	q2.tq = 4;
	int returntq;	//play시마다 몇 초를 썼는지 확인하기 위해
	while (now < time) {
		if(k!=jobc)	newjob();
		if (q0.count != 0) {
///////////////////////////////////////////////////////////////////////////////////////
			returntq = q0.play();
			for (m = 0; m < returntq; m++) {
				print = print + q0.head->name + "|";
			}

			if (q0.head->servtime == 0) {
				q0.pop();
			}
			else {
				q1.push(q0.pop());
			}
			q0.count--;
			//}
		}
//////////////////////////////////////////////////////////////////////////////////
		else if (q1.count != 0) {

			returntq = q1.play();
			for (m = 0; m < returntq; m++) {
				print = print + q1.head->name + "|";
			}
			if (q1.head->servtime == 0) {
				q1.pop();
			}
			else {
				q2.push(q1.pop());
			}
			q1.count--;

		}
//////////////////////////////////////////////////////////////////////////////
		else if (q2.count != 0) {

			returntq = q2.play();
			for (m = 0; m < returntq; m++) {
				print = print + q2.head->name + "|";
			}

			if (q2.head->servtime == 0) {
				q2.pop();
			}
			else {
				job* tmp = q2.pop();
				q2.push(tmp);
			}			
			q2.count--;

		}
		else {
			print = print + "  |";
			time++;
		}


		now = now + returntq;
	}

	cout << "MLFQ : " << print << endl;
	
}

mlfq::~mlfq()
{
}
