#include "rr.h"



rr::rr(int** _jobs, int _jobc, int tq)
{			//mlfq ������
	jobs = _jobs;
	jobc = _jobc;
	for (m = 0; m < jobc; m++) {		//�� ����ð��� �󸶳� �Ǵ��� ���
		time = time + jobs[m][0];
	}
	q.tq = tq;		//�Է¹��� tq�� ����
}


rr::~rr()
{
}

void rr::newjob()
{
	if (jobs[k][0] <= now) {		//�� time slice�� ���� ������ ���� ���� job�� �ִ��� Ȯ��
		q.push(new job(jobs[k][0], jobs[k][1], name));
		//���� ������ ť�� �־��ش�
		k++;
		name++;
	}
}
void rr::RR_job()
{
	job* tmp = NULL;
	int returntq;	//play�ø��� �� �ʸ� ����� Ȯ���ϱ� ����
	while (now < time) {		//���� �ð��� �� ����ð����� ������ while�� ����. Ŀ���� ������
		if (k != jobc)	newjob();	//���� ť�� push�� job�� ������ �� job�� �������� ������ ���ο� job�� �ִ��� �˻�
		if (tmp != NULL) {
			q.push(tmp);		//tmp�� � job�� �ִٸ� push �� �ش�.
			tmp = NULL;
		}
		if (q.count == 0) {			//���� ť�� �ƹ��͵� ������ ������ ����Ʈ�Ѵ�
			now++;
			time++;					//�� ����ð����� �ϳ��� �þ���Ƿ� �ϳ� �����ش�
			print = print + "  |";
		}
	
		//////////////////////////////////////////////////////////////////////////////////////
		
		else {
			returntq = q.play();		//ť�� �����ϰ� ��ŭ�� �ð����� �����ߴ��� ���Ϲ޴´�
			for (m = 0; m < returntq; m++) {		//������ ��ŭ ����� ��Ʈ���� �����Ѵ�. (|A|A|)
				print = print + q.head->name + "|";
			}

			if (q.head->servtime == 0) {	//��� ������ job�� ���� ����ð��� 0�̶�� ť���� �����Ѵ�
				q.pop();
			}
			else {			//����ð��� 0�� �ƴ϶� ���� ���Ҵٸ� ť���� �����Ѵ�
				tmp = q.pop();	//tmp�� ������ �ΰ� ���� while�� �� �ٽ� push �� �ش�
				//q.push(tmp);
			}
//			q.count--;		//job�� �̹� ����Ǿ����Ƿ� ť�� ī��Ʈ�� --�Ѵ�.
			now = now + returntq;	//���� �ð��� ��� ����� job�� ��ŭ ����Ǿ����� �����ش�.
		}
	}

	cout << "RR : " << print << endl;		//��� job�� ������ �� ������ � ������ ����Ǿ����� ����Ѵ�.

}