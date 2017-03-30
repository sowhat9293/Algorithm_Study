#include <iostream>
using namespace std;

class SortRule	//����Ŭ����
{
public:
	virtual bool operator() (int num1, int num2) const = 0;	//���������Լ��� ���� �� Ŭ������ �߻� Ŭ������ ��.
};

class AscendingSort	//��������
	: public SortRule
{
public:
	bool operator() (int num1, int num2) const	//����Ŭ�������� �Լ��� �����Ͽ���.
	{
		if (num1 > num2)
			return true;
		else
			return false;
	}
};

class DescendingSort	//��������
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
			cout << "�� �̻� ������ �Ұ����մϴ�." << endl;
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
	DataStorage storage(5);	//�����ڸ� ���Ͽ� ���̰� 5�� ������ �迭�� �����Ҵ��Ѵ�.
	storage.AddData(40);	// arr[0] = 40
	storage.AddData(30);	// arr[1] = 30
	storage.AddData(50);	// arr[2] = 50
	storage.AddData(20);	// arr[3] = 20
	storage.AddData(10);	// arr[4] = 10

	storage.SortData(AscendingSort());	//�Լ��� ���ڷ� �ӽ� ��ü�� �������� ���޵ȴ�.
	storage.ShowAllData();

	storage.SortData(DescendingSort());
	storage.ShowAllData();

	return 0;
}

// ���������� ���������� ��Ӱ� �����Լ��� �̿��Ͽ� ǥ���� �ҽ��̴�. �̷��� ������ ���������̶� �Ѵ�.