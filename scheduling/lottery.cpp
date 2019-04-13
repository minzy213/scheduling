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
	int max = 0;	//총 티켓 갯수
	cout << "몇 개의 job인지 입력하세요 : ";
	cin >> count;

	int** jobs = new int*[count];
	for (i = 0; i < count; i++) {
		jobs[i] = new int[4];
	}
	int k = 1;
	for (i = 0; i < count; i++) {
		cout << i + 1 << "번째 job의 ticket 갯수를 입력하세요 : ";
		cin >> jobs[i][1];	//1 : 해당 job이 몇 개의 티켓을 가지는지
		jobs[i][0] = k;		//0 : job의 이름
		jobs[i][3] = 0;		//3 : 몇 번이나 job이 실행되었는지(rand)
		k++;
		max = max + jobs[i][1];		//max : 총 티켓 갯수
	}
	//2 : 이 job이 몇 번 까지의 티켓을 가지고 있는지.
	jobs[0][2] = jobs[0][1];		//첫 번째 job은 0~본인 티켓 갯수 까지이므로 2=1 해준다
	for (i = 1; i < count; i++) {
		jobs[i][2] = jobs[i - 1][2] + jobs[i][1];		//현재 job의 [2]를 정하는 방법 : 이전 job의 [2] + 현재 job의 [1]
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
		cout << jobs[i][0] << "의 확률\n======\n예상 : " << tmp << endl;
		tmp = (double)jobs[i][3] / (double)(max);
		cout << "결과 : " << tmp << "\n\n";
	}

}
