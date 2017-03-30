#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int StoI(char * str)		//문자열을 정수로 변환하는 함수
{
	int len=strlen(str);
	int num=0;

	for(int i=0; i<len; i++)
	{
		if(str[i]<'0' || str[i]>'9')	//정수 문자가 아닐경우
			throw str[i];
		num += (int)(pow((double)10, (len-1)-i) * (str[i]+(7-'7')));
	}
	return num;
}

int main()
{
	char str1[100];
	char str2[100];

	while(1)
	{
		cout<<"두 개의 숫자 입력 : ";
		cin>>str1>>str2;

		try
		{
			cout<<str1<<" + "<<str2<<" = "<<StoI(str1)+StoI(str2)<<endl;
			break;
		}
		catch(char ch)
		{
			cout<<"문자 "<<ch<<"가 입력되었습니다."<<endl;
			cout<<"재입력 진행합니다."<<endl<<endl;
		}
	}
	cout<<"프로그램을 종료합니다."<<endl;	// 예외가 발생하지 않고 break문을 만나 while문이 종료되었을때 실행되는 코드라인	
	return 0;
}
// try, catch 예외와 문자열을 정수로 변환하는 알고리즘