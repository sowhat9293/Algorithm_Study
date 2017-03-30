#include <stdio.h>
typedef struct Arr
{
	int num[3];
}Arr;
 
int main()
{
	Arr ar[11]={
		{8,7,10}, {0,2,2}, {0,6,12}, {1,4,7}, {2,0,23}, {3,3,31},
		{4,1,14}, {4,5,25}, {5,6,6}, {6,0,52}, {7,4,11}
	};
	Arr cp[11];
	int i,k;
	int cpnum=1;
	cp[0].num[0]=ar[0].num[1];
	cp[0].num[1]=ar[0].num[0];
	cp[0].num[2]=ar[0].num[2];
	for( k=0; k<7; k++)	//열의 번호
	{
	for ( i=1; i<11; i++)		// 행의 번호문
	{
		if( ar[i].num[1] == k )	//대입문
		{
			cp[cpnum].num[0]=ar[i].num[1];
			cp[cpnum].num[1]=ar[i].num[0];
			cp[cpnum].num[2]=ar[i].num[2];
			cpnum++;
		}
	}
	}
	printf("--원래 행렬--\n");
	for(i=0; i<11; i++)
	{
		printf("%d	%d		%d\n", ar[i].num[0],ar[i].num[1],ar[i].num[2] );
	}
	printf("--전치 행렬--\n");
	for(i=0; i<11; i++)
	{
		printf("%d	%d		%d\n", cp[i].num[0],cp[i].num[1],cp[i].num[2] );
	}
	return 0;
}

// 전치 행렬을 구하는 프로그램이다.
// 둘 이상의 반복문으로 프로그램이 구성이 될 때 알고리즘을 짜는 순서는 중요하다.
// 직접 손으로 그림을 그려보며 알고리즘을 구현하면 훨씬 더 쉽게 구현할 수 있다.
// Tip. 반복되어야 하는 실행이 무엇인지 파악한 후, 반복되어야 할 변수를 정한다.
// 이 소스에서는 처음 접근이 안으로 들어갔고, 후 접근이 제일 바깥의 반복문으로 덮혀져있다.