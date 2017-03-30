#include <iostream>
using namespace std;
 
typedef int * INT_PTR;
class BoundCheck2DIntArray
{
private:
	int LINE;	//행의 길이
	int ROW;	//열의 길이
	INT_PTR * arr;
	BoundCheck2DIntArray(const BoundCheck2DIntArray & ref) {}
	BoundCheck2DIntArray& operator=(BoundCheck2DIntArray & ref) {}
public:
	BoundCheck2DIntArray(int line, int row)
		: LINE(line), ROW(row)
	{
		arr=new INT_PTR[line];
		for ( int i=0; i < line; i++ )
		{
			arr[i]=new int[row];
		}
	}
	INT_PTR& operator[] ( int idx )
	{
		if( idx < 0 || idx >= LINE )
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);	//비정상적으로 프로그램이 종료되었음을 알리는 반환문
		}
		return arr[idx];
	}
	INT_PTR operator[] ( int idx ) const
	{
		if( idx < 0 || idx >= LINE )
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);	//비정상적으로 프로그램이 종료되었음을 알리는 반환문
		}
		return arr[idx];
	}
 
};
 
int main()
{
	BoundCheck2DIntArray arr2d(3, 4);
	for ( int i=0; i<3; i++)
	{
		for( int j=0; j<4; j++ )
		{
			arr2d[i][j]=i*2+j;
		}
	}
 
	for ( int i=0; i<3; i++)
	{
		for( int j=0; j<4; j++ )
		{
			cout<<"arr["<<i<<"]["<<j<<"] = ";
			cout<<arr2d[i][j]<<endl;	// == (arr2d.operator[] (i)).operator[] (j) == arr[i].operator[] (j) == (배열)
		}
	}
 
	return 0;
 
}

// 클래스로 정수형 2차원 배열을 구현한 프로그램이다.
// 연산자 오버로딩은 클래스 변수의 함수이다.
// 즉, 클래스로 접근하는 것이고, 위 소스와 같이 연산자를 두번 호출하는 경우는 반환형의 함수 호출이다.
// 그런데 위 소스의 처음 []연산자 오버로딩의 반환 형은 int * 이다. int *의 []오버로딩은 디폴트로 있기때문에
// 구현하지 않아도 됬었다.