#include <iostream>
#include <ctime>
using namespace std;

int main()
{	
	int tt = time(NULL);
	int sec;
	int min;
	int key;	//������ �Է� ���� ����
	int randNum;	//����
	int preMin;
	min = (int)(((tt%86400)%3600) / 60);
	srand(min);
	randNum = rand();
	while (1)
	{
		tt = time(NULL);
		preMin = (int)(((tt % 86400) % 3600) / 60);	// ������ ��
		if (min < preMin)	//1���� ������ �ڵ����� ���� ����
		{
			srand(preMin);
			randNum = rand();
			min = preMin;
		}
		cout << "���� ������ ������ " << randNum << " �Դϴ�." << endl;
		cout << "������ �ϳ� �Է��Ͻÿ� : ";
		cin >> key;
		if (key == randNum)
		{
			cout << "������ �Է��� ���� �����Ƿ� ������ �����մϴ�." << endl;
			return 0;
		}

	}
	return 0;
}
// 1�� ���� ������ ���� ���������ְ� �� ������ ���߸� ���α׷��� ����Ǵ� �ҽ�