#include <iostream>
#include <ctime>
using namespace std;

int main()
{	
	int tt = time(NULL);
	int sec;
	int min;
	int key;	//난수를 입력 받을 변수
	int randNum;	//난수
	int preMin;
	min = (int)(((tt%86400)%3600) / 60);
	srand(min);
	randNum = rand();
	while (1)
	{
		tt = time(NULL);
		preMin = (int)(((tt % 86400) % 3600) / 60);	// 현재의 분
		if (min < preMin)	//1분이 지나면 자동으로 난수 생성
		{
			srand(preMin);
			randNum = rand();
			min = preMin;
		}
		cout << "현제 생성된 난수는 " << randNum << " 입니다." << endl;
		cout << "난수를 하나 입력하시오 : ";
		cin >> key;
		if (key == randNum)
		{
			cout << "난수와 입력한 수가 같으므로 보안을 해제합니다." << endl;
			return 0;
		}

	}
	return 0;
}
// 1분 마다 난수를 새로 생성시켜주고 그 난수를 맞추면 프로그램이 종료되는 소스