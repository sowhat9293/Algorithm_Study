#include <iostream>
using namespace std;

class SortRule	//기초클래스
{
public:
	virtual bool operator() (int num1, int num2) const = 0;	//순수가상함수로 인해 이 클래스는 추상 클래스가 됨.
};

class AscendingSort	//오름차순
	: public SortRule
{
public:
	bool operator() (int num1, int num2) const	//유도클래스에서 함수를 정의하였다.
	{
		if (num1 > num2)
			return true;
		else
			return false;
	}
};

class DescendingSort	//내림차순
	: public SortRule
{
public:
	bool operator() (int num1, int num2) const
	{
		if (num1 < num2)
			return true;
		else
			return false;
	}
};

class DataStorage
{
private:
	int * arr;
	int idx;
	const int MAX_LEN;
public:
	DataStorage(int arrlen)
		: idx(0), MAX_LEN(arrlen)
	{
		arr = new int[MAX_LEN];
	}
	void AddData(int num)
	{
		if (MAX_LEN <= idx)
		{
			cout << "더 이상 저장이 불가능합니다." << endl;
			return;
		}
		arr[idx++] = num;
	}
	void ShowAllData()
	{
		for (int i = 0; i < idx; i++)
			cout << arr[i] << ' ';
		cout << endl;
	}
	void SortData(const SortRule & functor)
	{
		for (int i = 0; i < (idx - 1); i++)
		{
			for (int j = 0; j < (idx - 1); j++)
			{
				if (functor(arr[j], arr[j + 1]))
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
};

int main()
{
	DataStorage storage(5);	//생성자를 통하여 길이가 5인 정수형 배열의 동적할당한다.
	storage.AddData(40);	// arr[0] = 40
	storage.AddData(30);	// arr[1] = 30
	storage.AddData(50);	// arr[2] = 50
	storage.AddData(20);	// arr[3] = 20
	storage.AddData(10);	// arr[4] = 10

	storage.SortData(AscendingSort());	//함수의 인자로 임시 객체가 생성된후 전달된다.
	storage.ShowAllData();

	storage.SortData(DescendingSort());
	storage.ShowAllData();

	return 0;
}

// 오름차순과 내림차순을 상속과 가상함수를 이용하여 표현한 소스이다. 이러한 정렬을 버블정렬이라 한다.