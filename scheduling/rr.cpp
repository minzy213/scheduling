#include "rr.h"



rr::rr(int** _jobs, int _jobc, int tq)
{			//mlfq 생성자
	jobs = _jobs;
	jobc = _jobc;
	for (m = 0; m < jobc; m++) {		//총 실행시간이 얼마나 되는지 계산
		time = time + jobs[m][0];
	}
	q.tq = tq;		//입력받은 tq를 저장
}


rr::~rr()
{
}

void rr::newjob()
{
	if (jobs[k][0] <= now) {		//매 time slice가 끝날 때마다 새로 들어온 job이 있는지 확인
		q.push(new job(jobs[k][0], jobs[k][1], name));
		//만약 있으면 큐에 넣어준다
		k++;
		name++;
	}
}
void rr::RR_job()
{
	job* tmp = NULL;
	int returntq;	//play시마다 몇 초를 썼는지 확인하기 위해
	while (now < time) {		//현재 시간이 총 수행시간보다 적으면 while문 실행. 커지면 끝난다
		if (k != jobc)	newjob();	//지금 큐에 push된 job의 갯수가 총 job의 갯수보다 작으면 새로운 job이 있는지 검사
		if (tmp != NULL) {
			q.push(tmp);		//tmp에 어떤 job이 있다면 push 해 준다.
			tmp = NULL;
		}
		if (q.count == 0) {			//현재 큐에 아무것도 없으면 공백을 프린트한다
			now++;
			time++;					//총 수행시간보다 하나가 늘어났으므로 하나 더해준다
			print = print + "  |";
		}
	
		//////////////////////////////////////////////////////////////////////////////////////
		
		else {
			returntq = q.play();		//큐를 실행하고 얼만큼의 시간동안 실행했는지 리턴받는다
			for (m = 0; m < returntq; m++) {		//실행한 만큼 출력할 스트링에 저장한다. (|A|A|)
				print = print + q.head->name + "|";
			}

			if (q.head->servtime == 0) {	//방금 실행한 job의 남은 수행시간이 0이라면 큐에서 삭제한다
				q.pop();
			}
			else {			//수행시간이 0이 아니라 아직 남았다면 큐에서 삭제한다
				tmp = q.pop();	//tmp에 저장해 두고 다음 while문 때 다시 push 해 준다
				//q.push(tmp);
			}
//			q.count--;		//job이 이미 실행되었으므로 큐의 카운트를 --한다.
			now = now + returntq;	//현재 시간에 방금 수행된 job이 얼만큼 실행되었는지 더해준다.
		}
	}

	cout << "RR : " << print << endl;		//모든 job의 수행이 다 끝나면 어떤 순서로 실행되었는지 출력한다.

}