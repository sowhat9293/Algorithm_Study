#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void build_max_hip(int * ptr, int index);
void max_heapify(int * ptr);

int size;

int main()
{
	int arr[11] = {0,4,1,3,2,16,9,10,14,8,7};			// size�� 10, ó�� 0�� index�� 1���� �����ϱ� ����.
	int i=1;
	size = sizeof(arr) / sizeof(int) - 1;		//10
	printf("[���� �迭]\n");
	for(i=1; i<=10; i++)
	{
		printf("%d ", arr[i]);
	}	// ���� �迭 ���
	for(i=5; i>=1; i--)
	{
		build_max_hip(arr,i);
	}
	printf("\n[�� ������ ���� �迭]\n");
	for(i=1; i<=10; i++)
	{
		printf("%d ", arr[i]);
	}	// �� ������ ���� �� ���
	printf("\n");
	for(i=0; i < 10; i++)
		max_heapify(arr);
	printf("[�ִ��� ���� -> �������� ����]\n");
	for(i=1; i<=10; i++)
	{
		printf("%d ", arr[i]);
	}	// ���� ������������ ������
	printf("\n");
	return 0;
}

void build_max_hip(int * ptr, int index)			//���� ����� �޼ҵ�, ���ڷ� �迭��, �� �迭 ������ - 1(������ ����� index)
{
	int i;
	if( index*2 > size )			// �ڽ��� �ϳ��� ���� ��
		return;
	else if ( index*2 + 1 > size )	// �ڽ��� ���ʸ� ���� ��
	{
		if(ptr[index*2] > ptr[index] )	// ���� �ڽ��� �θ� ���� Ŭ ��
		{
			int temp = ptr[index*2];
			ptr[index*2] = ptr[index];
			ptr[index] = temp;
			build_max_hip(ptr, index*2);	// �ٲ� �ڽĳ���� ��ġ�� �ٽ� �θ�����ؼ� ���ȣ��
		}
	}
	else							// �ڽ��� �� �� ���� ��
	{
		if(ptr[index*2] >= ptr[index*2 +1] && ptr[index*2] > ptr[index])	// ���� >= ������ && ���� > �θ�
		{
			int temp = ptr[index*2];
			ptr[index*2] = ptr[index];
			ptr[index] = temp;
			build_max_hip(ptr, index*2);	// �ٲ� �ڽĳ���� ��ġ�� �ٽ� �θ�����ؼ� ���ȣ��
		}
		else if(ptr[index*2] < ptr[index*2 +1] && ptr[index*2+1] > ptr[index])	// ������ > ���� && ������ > �θ�
		{
			int temp = ptr[index*2 +1];
			ptr[index*2+1] = ptr[index];
			ptr[index] = temp;
			build_max_hip(ptr, index*2+1);	// �ٲ� �ڽĳ���� ��ġ�� �ٽ� �θ�����ؼ� ���ȣ��
		}
	}
}

void max_heapify(int * ptr)
{
	int root_node = ptr[1];		// �ֻ��� ����� ��
	int i;
	ptr[1] = ptr[size];			// ������ ��� ���� �ֻ����� ����ġ
	ptr[size] = root_node;		// ��Ʈ��忡 �ִ� ���� ���� ���������� ����
	size--;
	for(i = size / 2; i >= 1; i--)
	{
		build_max_hip(ptr,i);		// ������
	}
}

