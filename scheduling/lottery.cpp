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
	char k = 'A';
	for (i = 0; i < count; i++) {
		cout << i + 1 << "��° job�� ticket ������ �Է��ϼ��� : ";
		cin >> jobs[i][1];
		jobs[i][0] = k;
		jobs[i][3] = 0;
		k++;
		max = max + jobs[i][1];
	}
	jobs[0][2] = jobs[0][1];
	for (i = 1; i < count; i++) {
		jobs[i][2] = jobs[i - 1][2] + jobs[i][1];
	}

	int j;

	srand(time(NULL));
	for (i = 1; i <= max / 5; i++) {
		ran = (rand() % max -1) + 1;
		for (j = 0; j < count; j++) {
			if (jobs[j][2] > ran) {
				jobs[j][3]++;
				cout << rand << "  " << jobs[j][0];
			}
		}
	}


}
