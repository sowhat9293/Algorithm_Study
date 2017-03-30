#include <iostream>
using namespace std;
 
typedef int * INT_PTR;
class BoundCheck2DIntArray
{
private:
	int LINE;	//���� ����
	int ROW;	//���� ����
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
			exit(1);	//������������ ���α׷��� ����Ǿ����� �˸��� ��ȯ��
		}
		return arr[idx];
	}
	INT_PTR operator[] ( int idx ) const
	{
		if( idx < 0 || idx >= LINE )
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);	//������������ ���α׷��� ����Ǿ����� �˸��� ��ȯ��
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
			cout<<arr2d[i][j]<<endl;	// == (arr2d.operator[] (i)).operator[] (j) == arr[i].operator[] (j) == (�迭)
		}
	}
 
	return 0;
 
}

// Ŭ������ ������ 2���� �迭�� ������ ���α׷��̴�.
// ������ �����ε��� Ŭ���� ������ �Լ��̴�.
// ��, Ŭ������ �����ϴ� ���̰�, �� �ҽ��� ���� �����ڸ� �ι� ȣ���ϴ� ���� ��ȯ���� �Լ� ȣ���̴�.
// �׷��� �� �ҽ��� ó�� []������ �����ε��� ��ȯ ���� int * �̴�. int *�� []�����ε��� ����Ʈ�� �ֱ⶧����
// �������� �ʾƵ� �����.