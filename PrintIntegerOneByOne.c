#include <stdio.h>


int main()
{
	 int hak=2012301034;
	 int arr[10];
	 int i=0;
	 int j;
	 while(1)
	 {
		 if(hak / 10 != 0)
		 {
		 arr[i]=(hak - ( (hak/10) * 10 ) );
		 hak /= 10;
		 i++;
		 }
		 else
		 {
			arr[i]=hak;
			break;
		 }
	 }
	 for(j=9; j>=0; j--)
		 printf("%d\n", arr[j]);
	 return 0;
}
// �Է��� ������ ������� �ϳ��� ����ϴ� �˰��� ���α׷�