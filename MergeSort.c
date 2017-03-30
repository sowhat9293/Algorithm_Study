#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* divide(int * ptr, int f, int l);

int main()
{
	int arr2[1024] ;
	int i;
	int size = sizeof(arr2) / sizeof(int);
	int * ptr = NULL;
	// �迭 ���� �ʱ�ȭ �κ�
	srand((unsigned int) time(NULL));
	for(i=0; i<size; i++)
		arr2[i] = rand() % 10000 + 1;
	//
	printf("[���� �迭]\n");
	for(i=0; i<size; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n\n[�պ� ���ĵ� �迭]\n");
	ptr = divide(arr2, 0, size-1);
	for(i=0; i<size; i++)
		printf("%d ", arr2[i]);
	printf("\n");
	return 0;
}

int* divide(int * ptr, int f, int l)		// ���� �迭 , ù��° �ε���, ������ �ε���
{
	if(f < l)		// ����
	{
		int i,j, k;
		int n = (f + l) /2;					// �߰� �ε���
		int size = l-f + 1;					// �迭 ������
		int * sum_ptr = (int*)malloc(sizeof(int) * size);		//�Ű� ���� �迭
		int * ptr1 = divide(ptr, f, n);		// ��ȯ�� ���� index�� f, ���� n
		int * ptr2 = divide(ptr, n+1, l);	// ��ȯ�� ���� index�� n+1, ���� l

		for(i=0, j=0, k=0; k < size; )
		{
			sum_ptr[k++] = ptr1[i] <= ptr2[j] ? ptr1[i++] : ptr2[j++];
			if( i  == size/2 )		// �ϳ��� �迭�� ��� ������
			{
				while ( k < size )
				{
					sum_ptr[k++] = ptr2[j++];
				}
			}
			else if ( j == size/2 )
			{
				while ( k < size )
				{
					sum_ptr[k++] = ptr1[i++];
				}
			}
			
		}
		for(i = 0, j = f; i < size; i++, j++)
		{
			ptr[j] = sum_ptr[i] ;
		}
		return &ptr[f];
	}
	else			// ���Ұ� �� �ɰ����� �ϳ��� ���� ����
	{
		return &ptr[f];
	}
}


// �պ� ���� �ҽ�