#include "lottery.h"



lottery::lottery()
{
}


lottery::~lottery()
{
}

void lottery::lotterymain() 
{
	int count, i, ran;
	int max = 0;	//�� Ƽ�� ����
	cout << "�� ���� job���� �Է��ϼ��� : ";
	cin >> count;

	int** jobs = new int*[count];
	for (i = 0; i < count; i++) {
		jobs[i] = new int[4];
	}
	int k = 1;
	for (i = 0; i < count; i++) {
		cout << i + 1 << "��° job�� ticket ������ �Է��ϼ��� : ";
		cin >> jobs[i][1];	//1 : �ش� job�� �� ���� Ƽ���� ��������
		jobs[i][0] = k;		//0 : job�� �̸�
		jobs[i][3] = 0;		//3 : �� ���̳� job�� ����Ǿ�����(rand)
		k++;
		max = max + jobs[i][1];		//max : �� Ƽ�� ����
	}
	//2 : �� job�� �� �� ������ Ƽ���� ������ �ִ���.
	jobs[0][2] = jobs[0][1];		//ù ��° job�� 0~���� Ƽ�� ���� �����̹Ƿ� 2=1 ���ش�
	for (i = 1; i < count; i++) {
		jobs[i][2] = jobs[i - 1][2] + jobs[i][1];		//���� job�� [2]�� ���ϴ� ��� : ���� job�� [2] + ���� job�� [1]
	}

	int j;

	srand(time(NULL));
	i = 0;
	while (i < max) {
		ran = (rand() % max -1) + 1;
		for (j = 0; j < count; j++) {
			if (jobs[j][2] > ran) {
				jobs[j][3]++;
				//cout << ran << "  " << jobs[j][0] << endl;
				i++;
			}
		}
	}
	double tmp;
	for (i = 0; 1 < count; i++) {
		tmp = (double)jobs[i][1] / (double)max;
		cout << jobs[i][0] << "�� Ȯ��\n======\n���� : " << tmp << endl;
		tmp = (double)jobs[i][3] / (double)(max);
		cout << "��� : " << tmp << "\n\n";
	}

}
