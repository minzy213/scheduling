#include "job.h"


job::job() {

}
job::job(int a, int s, char n)
{		//job의 생성자. 
	arrtime = a;
	servtime = s;
	next = NULL;
	name = n;
}

job* job::getnext()		//큐의 다음 요소를 가져오기 위한 메서드
{						//this가 마지막 요소라면 next는 null
	return next;
}

void job::setnext(job* j)	//큐의 다음 요소를 next로 저장
{
	next = j;
}

int job::play(int tq) {		//job이 실행되는것. tq를 입력받아서 
	if (servtime < tq) tq = servtime;	//지금 남아있는 servtime이 tq보다 작으면 그만큼만 실행.
	servtime = servtime - tq;			//지금 남아있는 servtime이 tq보다 크다면 tq만큼만 실행.
	return tq;							//얼마나 실행했는지 리턴해준다
}

job::~job()
{
}
