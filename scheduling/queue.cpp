#include "queue.h"



queue::queue()
{
	head == NULL;
	tail == NULL;

}

void queue::push(job* j)
{
	if (count == 0) {
		head = j;
		tail = j;
	}
	else {
		tail->setnext(j);
		tail = j;
	}
	count++;
}
job* queue::pop()
{
	if (count == 0) return NULL;
	if (count == 1) {
		job* tmp = head;
		head = NULL;
		tail = NULL;
		return tmp;

	}
	else {
		job* tmp = head;
		head = head->getnext();		//큐의 맨 앞의 요소를 지우고
		return tmp;					//리턴한다
	}
	count--;
}

int queue::play()
{
	return head->play(tq);
	
}

void queue::newpush(job* j)
{
	if (count == 0) {
		head = j;
		tail = j;
	}
	else {
		job* tmp = NULL;
		tmp = head;
		head = j;
		j->setnext(tmp);
	}
	count++;
}

void queue::print()
{
	job* tmp = head;
	for (int i = 0; i < count; i++) {
		cout << tmp->name << "  ";
		tmp = tmp->next;
	}
}
queue::~queue()
{
}
