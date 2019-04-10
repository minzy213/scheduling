#include "mlfq.h"



mlfq::mlfq(int** _jobs, int _jobc)
{			//mlfq ������
	jobs = _jobs;
	jobc = _jobc;
	for (m = 0; m < jobc; m++) {		//�� ����ð��� �󸶳� �Ǵ��� ���
		time = time + jobs[m][0];
	}
}

void mlfq::newjob()
{
	if (jobs[k][0] <= now) {		//�� time slice�� ���� ������ ���� ���� job�� �ִ��� Ȯ��
		q0.newpush(new job(jobs[k][0], jobs[k][1], name));
					//���� ������ ù��° ť�� �־��ش�
		k++;
		name++;		
	}
}

void mlfq::mlfqmain()		//mlfq�� ���ϴ� ����
{
	q0.tq = 1;		//�� ť���� tq�� ���صд�.
	q1.tq = 2;		
	q2.tq = 4;
	int returntq;	//play�ø��� �� �ʸ� ����� Ȯ���ϱ� ����
	while (now < time) {		//���� �ð��� �� ����ð����� ������ while�� ����. Ŀ���� ������
		if(k!=jobc)	newjob();	//���� q0�� push�� job�� ������ �� job�� �������� ������ ���ο� job�� �ִ��� �˻�
		
		//////////////////////////////////////////////////////////////////////////////////////
		//q0�� job�� ��������� q0�� �� ���� job�� tq��ŭ �����Ѵ�
		if (q0.count != 0) {
			returntq = q0.play();		//q0�� �����ϰ� ��ŭ�� �ð����� �����ߴ��� ���Ϲ޴´�
			for (m = 0; m < returntq; m++) {		//������ ��ŭ ����� ��Ʈ���� �����Ѵ�. (|A|A|)
				print = print + q0.head->name + "|";
			}

			if (q0.head->servtime == 0) {	//��� ������ job�� ���� ����ð��� 0�̶�� q0���� �����Ѵ�
				q0.pop();
			}
			else {			//����ð��� 0�� �ƴ϶� ���� ���Ҵٸ� q0���� �����ϰ� q1�� push���ش�.
				q1.push(q0.pop());
			}
			q0.count--;		//job�� �̹� ����Ǿ����Ƿ� q0�� ī��Ʈ�� --�Ѵ�.
			
		}
		//���� �۾��� �Ȱ��� q1, q2���� �ݺ��Ѵ�.
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
				q2.push(q2.pop());	//q2�� �� �Ʒ� ť�̹Ƿ� �ٽ� q2�� push�Ѵ�
			}			
			q2.count--;

		}
		else {		//q0, q1, q2 ��� ����ٸ� ��ĭ�� ������ְ� �� ����ð��� ++�Ѵ�.
			print = print + "  |";
			time++;
		}


		now = now + returntq;	//���� �ð��� ��� ����� job�� ��ŭ ����Ǿ����� �����ش�.
	}

	cout << "MLFQ : " << print << endl;		//��� job�� ������ �� ������ � ������ ����Ǿ����� ����Ѵ�.
	
}

mlfq::~mlfq()
{
}
