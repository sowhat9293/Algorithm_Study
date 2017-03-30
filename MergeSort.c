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
	// 배열 난수 초기화 부분
	srand((unsigned int) time(NULL));
	for(i=0; i<size; i++)
		arr2[i] = rand() % 10000 + 1;
	//
	printf("[기존 배열]\n");
	for(i=0; i<size; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n\n[합병 정렬된 배열]\n");
	ptr = divide(arr2, 0, size-1);
	for(i=0; i<size; i++)
		printf("%d ", arr2[i]);
	printf("\n");
	return 0;
}

int* divide(int * ptr, int f, int l)		// 나눌 배열 , 첫번째 인덱스, 마지막 인덱스
{
	if(f < l)		// 수행
	{
		int i,j, k;
		int n = (f + l) /2;					// 중간 인덱스
		int size = l-f + 1;					// 배열 사이즈
		int * sum_ptr = (int*)malloc(sizeof(int) * size);		//옮겨 닮을 배열
		int * ptr1 = divide(ptr, f, n);		// 반환의 시작 index는 f, 끝은 n
		int * ptr2 = divide(ptr, n+1, l);	// 반환의 시작 index는 n+1, 끝은 l

		for(i=0, j=0, k=0; k < size; )
		{
			sum_ptr[k++] = ptr1[i] <= ptr2[j] ? ptr1[i++] : ptr2[j++];
			if( i  == size/2 )		// 하나의 배열이 모두 들어갔을때
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
	else			// 원소가 다 쪼개져서 하나만 남은 상태
	{
		return &ptr[f];
	}
}


// 합병 정렬 소스