#include "queue.h"


//큐는 포인터로 연결되고, 처음과 끝을 나타내기 위해 head와 tail을 사용한다.
queue::queue()
{			//큐의 생성자
	head == NULL;		//처음 생겼을 때는 아무 것도 없는 상태이므로 
	tail == NULL;		//head와 tail 모두 null로 설정해 준다.

}
		//새로운 job이 맨 마지막에 생기는 것을 push라고 한다. 
void queue::push(job* j)
{		
	if (count == 0) {		//큐에 아무것도 없는 상태에서 job이 새로 들어오면
		head = j;		//head와 tail 모두 새로 들어온 job으로 설정해 준다.
		tail = j;
	}
	else {		//큐에 하나라도 들어있는 상태에서 새로운 job이 들어오면
		tail->setnext(j);		//현재 tail의 next로 새 job을 설정해 주고
		tail = j;				//새로 들어온 job을 tail로 만들어 준다.
	}
	count++;			//큐에 들어있는 job의 갯수를 ++ 해 준다.
}
		//맨 앞의 job을 없애는 것을 pop이라고 한다.
		//방금 사라진 job을 리턴하는 메서드이다.
job* queue::pop()
{
	if (count == 0) return NULL;		//만약 현재 아무것도 없는 상태라면 null을 리턴해 준다.
	if (count == 1) {			//하나만 있는 상태라면
		job* tmp = head;		//현재 있는 job을 tmp에 저장해 두고
		head = NULL;			//head와 tail을 모두 null로 설정한 다음
		tail = NULL;
		return tmp;				//tmp를 리턴해 준다.

	}
	else {					//큐에 두개 이상의 job이 들어 있으면
		job* tmp = head;			//현재 head를 tmp에 저장해 두고
		head = head->getnext();		//head의 next를 head로 지정하고
		head->~job();				// 큐의 맨 앞의 요소를 지우고
		return tmp;					//tmp를 리턴한다
	}
	count--;			//큐에서 job 하나가 사라졌으므로 -- 해 준다.
}

int queue::play()
{
	return head->play(tq);		//현재 head의 play 메서드를 호출한다. 해당 job이 실행되었다는 뜻.
	
}

//새로운 job이 생겼을 때는 최우선 큐에 맨 앞에 넣어야 하므로 따로 만들어 준다.(가장 먼저 실행)
void queue::newpush(job* j)
{				
	if (count == 0) {		//만약 현재 큐에 아무것도 없다면
		head = j;			//head와 tail 모두 새로 생긴 job으로 만들어 준다.
		tail = j;
	}
	else {			//현재 큐에 하나라도 있다면
		job* tmp;			
		tmp = head;			//현재 head를 tmp에 저장해 두고
		head = j;			//head를 새로 들어온 job으로 설정하고
		head->setnext(tmp);	//head의 next를 tmp(이전의 head)로 지정해 준다.
	}
	count++;		//큐에 새로운 job이 생겼으므로 ++ 해 준다.
}

queue::~queue()
{
}
