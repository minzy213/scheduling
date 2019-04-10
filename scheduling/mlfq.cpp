#include "mlfq.h"



mlfq::mlfq(int** _jobs, int _jobc)
{			//mlfq 생성자
	jobs = _jobs;
	jobc = _jobc;
	for (m = 0; m < jobc; m++) {		//총 실행시간이 얼마나 되는지 계산
		time = time + jobs[m][0];
	}
}

void mlfq::newjob()
{
	if (jobs[k][0] <= now) {		//매 time slice가 끝날 때마다 새로 들어온 job이 있는지 확인
		q0.newpush(new job(jobs[k][0], jobs[k][1], name));
					//만약 있으면 첫번째 큐에 넣어준다
		k++;
		name++;		
	}
}

void mlfq::mlfqmain()		//mlfq를 구하는 메인
{
	q0.tq = 1;		//각 큐마다 tq를 정해둔다.
	q1.tq = 2;		
	q2.tq = 4;
	int returntq;	//play시마다 몇 초를 썼는지 확인하기 위해
	while (now < time) {		//현재 시간이 총 수행시간보다 적으면 while문 실행. 커지면 끝난다
		if(k!=jobc)	newjob();	//지금 q0에 push된 job의 갯수가 총 job의 갯수보다 작으면 새로운 job이 있는지 검사
		
		//////////////////////////////////////////////////////////////////////////////////////
		//q0에 job이 들어있으면 q0의 맨 위의 job을 tq만큼 실행한다
		if (q0.count != 0) {
			returntq = q0.play();		//q0을 실행하고 얼만큼의 시간동안 실행했는지 리턴받는다
			for (m = 0; m < returntq; m++) {		//실행한 만큼 출력할 스트링에 저장한다. (|A|A|)
				print = print + q0.head->name + "|";
			}

			if (q0.head->servtime == 0) {	//방금 실행한 job의 남은 수행시간이 0이라면 q0에서 삭제한다
				q0.pop();
			}
			else {			//수행시간이 0이 아니라 아직 남았다면 q0에서 삭제하고 q1로 push해준다.
				q1.push(q0.pop());
			}
			q0.count--;		//job이 이미 실행되었으므로 q0의 카운트를 --한다.
			
		}
		//위의 작업을 똑같이 q1, q2에서 반복한다.
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
				q2.push(q2.pop());	//q2는 맨 아래 큐이므로 다시 q2로 push한다
			}			
			q2.count--;

		}
		else {		//q0, q1, q2 모두 비었다면 빈칸을 출력해주고 총 수행시간을 ++한다.
			print = print + "  |";
			time++;
		}


		now = now + returntq;	//현재 시간에 방금 수행된 job이 얼만큼 실행되었는지 더해준다.
	}

	cout << "MLFQ : " << print << endl;		//모든 job의 수행이 다 끝나면 어떤 순서로 실행되었는지 출력한다.
	
}

mlfq::~mlfq()
{
}
