#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void build_max_hip(int * ptr, int index);
void max_heapify(int * ptr);

int size;

int main()
{
	int arr[11] = {0,4,1,3,2,16,9,10,14,8,7};			// size는 10, 처음 0은 index를 1부터 시작하기 위함.
	int i=1;
	size = sizeof(arr) / sizeof(int) - 1;		//10
	printf("[기존 배열]\n");
	for(i=1; i<=10; i++)
	{
		printf("%d ", arr[i]);
	}	// 기존 배열 출력
	for(i=5; i>=1; i--)
	{
		build_max_hip(arr,i);
	}
	printf("\n[힙 구조로 만든 배열]\n");
	for(i=1; i<=10; i++)
	{
		printf("%d ", arr[i]);
	}	// 힙 구조로 만든 후 출력
	printf("\n");
	for(i=0; i < 10; i++)
		max_heapify(arr);
	printf("[최대힙 추출 -> 오름차순 정렬]\n");
	for(i=1; i<=10; i++)
	{
		printf("%d ", arr[i]);
	}	// 힙을 오름차순으로 재정렬
	printf("\n");
	return 0;
}

void build_max_hip(int * ptr, int index)			//힙을 만드는 메소드, 인자로 배열과, 총 배열 사이즈 - 1(마지막 노드의 index)
{
	int i;
	if( index*2 > size )			// 자식이 하나도 없을 때
		return;
	else if ( index*2 + 1 > size )	// 자식이 왼쪽만 있을 때
	{
		if(ptr[index*2] > ptr[index] )	// 왼쪽 자식이 부모 보다 클 때
		{
			int temp = ptr[index*2];
			ptr[index*2] = ptr[index];
			ptr[index] = temp;
			build_max_hip(ptr, index*2);	// 바뀐 자식노드의 위치를 다시 부모노드로해서 재귀호출
		}
	}
	else							// 자식이 둘 다 있을 때
	{
		if(ptr[index*2] >= ptr[index*2 +1] && ptr[index*2] > ptr[index])	// 왼쪽 >= 오른쪽 && 왼쪽 > 부모
		{
			int temp = ptr[index*2];
			ptr[index*2] = ptr[index];
			ptr[index] = temp;
			build_max_hip(ptr, index*2);	// 바뀐 자식노드의 위치를 다시 부모노드로해서 재귀호출
		}
		else if(ptr[index*2] < ptr[index*2 +1] && ptr[index*2+1] > ptr[index])	// 오른쪽 > 왼쪽 && 오른쪽 > 부모
		{
			int temp = ptr[index*2 +1];
			ptr[index*2+1] = ptr[index];
			ptr[index] = temp;
			build_max_hip(ptr, index*2+1);	// 바뀐 자식노드의 위치를 다시 부모노드로해서 재귀호출
		}
	}
}

void max_heapify(int * ptr)
{
	int root_node = ptr[1];		// 최상위 노드의 값
	int i;
	ptr[1] = ptr[size];			// 최하위 노드 값을 최상위로 스위치
	ptr[size] = root_node;		// 루트노드에 있던 값을 제일 마지막으로 보냄
	size--;
	for(i = size / 2; i >= 1; i--)
	{
		build_max_hip(ptr,i);		// 재정렬
	}
}

