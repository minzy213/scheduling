#include "queue.h"


//ť�� �����ͷ� ����ǰ�, ó���� ���� ��Ÿ���� ���� head�� tail�� ����Ѵ�.
queue::queue()
{			//ť�� ������
	head == NULL;		//ó�� ������ ���� �ƹ� �͵� ���� �����̹Ƿ� 
	tail == NULL;		//head�� tail ��� null�� ������ �ش�.

}
		//���ο� job�� �� �������� ����� ���� push��� �Ѵ�. 
void queue::push(job* j)
{		
	if (count == 0) {		//ť�� �ƹ��͵� ���� ���¿��� job�� ���� ������
		head = j;		//head�� tail ��� ���� ���� job���� ������ �ش�.
		tail = j;
	}
	else {		//ť�� �ϳ��� ����ִ� ���¿��� ���ο� job�� ������
		tail->setnext(j);		//���� tail�� next�� �� job�� ������ �ְ�
		tail = j;				//���� ���� job�� tail�� ����� �ش�.
	}
	count++;			//ť�� ����ִ� job�� ������ ++ �� �ش�.
}
		//�� ���� job�� ���ִ� ���� pop�̶�� �Ѵ�.
		//��� ����� job�� �����ϴ� �޼����̴�.
job* queue::pop()
{
	if (count == 0) return NULL;		//���� ���� �ƹ��͵� ���� ���¶�� null�� ������ �ش�.
	if (count == 1) {			//�ϳ��� �ִ� ���¶��
		job* tmp = head;		//���� �ִ� job�� tmp�� ������ �ΰ�
		head = NULL;			//head�� tail�� ��� null�� ������ ����
		tail = NULL;
		return tmp;				//tmp�� ������ �ش�.

	}
	else {					//ť�� �ΰ� �̻��� job�� ��� ������
		job* tmp = head;			//���� head�� tmp�� ������ �ΰ�
		head = head->getnext();		//head�� next�� head�� �����ϰ�
		head->~job();				// ť�� �� ���� ��Ҹ� �����
		return tmp;					//tmp�� �����Ѵ�
	}
	count--;			//ť���� job �ϳ��� ��������Ƿ� -- �� �ش�.
}

int queue::play()
{
	return head->play(tq);		//���� head�� play �޼��带 ȣ���Ѵ�. �ش� job�� ����Ǿ��ٴ� ��.
	
}

//���ο� job�� ������ ���� �ֿ켱 ť�� �� �տ� �־�� �ϹǷ� ���� ����� �ش�.(���� ���� ����)
void queue::newpush(job* j)
{				
	if (count == 0) {		//���� ���� ť�� �ƹ��͵� ���ٸ�
		head = j;			//head�� tail ��� ���� ���� job���� ����� �ش�.
		tail = j;
	}
	else {			//���� ť�� �ϳ��� �ִٸ�
		job* tmp;			
		tmp = head;			//���� head�� tmp�� ������ �ΰ�
		head = j;			//head�� ���� ���� job���� �����ϰ�
		head->setnext(tmp);	//head�� next�� tmp(������ head)�� ������ �ش�.
	}
	count++;		//ť�� ���ο� job�� �������Ƿ� ++ �� �ش�.
}

queue::~queue()
{
}
