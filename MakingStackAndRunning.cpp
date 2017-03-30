#include <iostream>
using namespace std;

class MyStack { 
private: 
	int * ptr;
	int size;
	int top;
public: 
// 스택의 데이터 저장 공간으로 크기가 8인 동적배열을 만드는 생성자 
MyStack()
{
	ptr=new int[8];
	size=8;
	top=0;
	cout<<"*** DEBUG *** MyStack::MyStack()에서 new를 이용하여 크기 "<<size<<"인 동적배열의 메모리를 할당"<<endl;
}

// 스택의 데이터 저장 공간으로 크기가 s보다 작지않은 최소의 8의 배수인 동적배열을 만드는 생성자 (예: s == 9 인 경우와 s == 16 인 경우 모두 크기가 16인 동적배열 생성) 
MyStack(int s)
{
	if ( s % 8 == 0 )
	{
		ptr=new int[s];
		size=s;
	}
	else
	{
		size=s+( 8 - s%8 );
		ptr=new int[size];
	}
	top=0;
	cout<<"*** DEBUG *** MyStack::MyStack(int s)에서 new를 이용하여 크기 "<<size<<"인 동적배열의 메모리를 할당"<<endl;
}

MyStack(const MyStack & stack) // 복사생성자, 5월 8일 수업시간에 설명 예정, 다른 부분부터 먼저 구현할 것 
{
	ptr=new int[stack.size];
	cout<<"*** DEBUG *** MyStack::push(int item)에서 new를 이용하여 크기 "<<stack.size<<"인 동적배열의 메모리를 할당"<<endl;
	for(int i=0; i<stack.top; i++)
	{
		ptr[i]=stack.ptr[i];
		top++;
	}
	/*for(int i=0; i<size; i++)
	{
		cout<<"data : "<<ptr[i]<<endl;
	}*/
	size=stack.size;
	top=stack.top;
}

// 동적배열을 삭제하는 소멸자 
~MyStack()
{
	if ( ptr != NULL )
	{
		delete[]ptr;
		cout<<"*** DEBUG *** MyStack::~MyStack()에서 delete를 이용하여 크기 "<<size<<"인 동적배열의 메모리를 반환"<<endl;
	}
}

// item 값을 스택에 push하는 함수(성공하면 true, 실패하면 false 반환) 
// 배열에 공간이 부족하면: 기존 배열크기의 2배인 새 배열을 new로 할당받음 
// -> 기존 데이터를 새 배열에 복사하고 item 값을 데이터에 추가 -> 기존 배열을 delete하고 새 배열을 이용함 
bool push(int item)
{
	if ( size == top )	// 배열에 모든 데이터가 다 차있을경우, 2배의 새배열을 new로 받아야한다.
	{
		MyStack temp(*this);
		delete[]ptr;
		cout<<"*** DEBUG *** MyStack::push(int item)에서 delete를 이용하여 크기 "<<size<<"인 동적배열의 메모리를 반환"<<endl;
		size *=2;
		ptr=new int[size];
		top=0;
		for(int i=0; i<temp.top; i++)
		{
			ptr[i]=temp.ptr[i];
			top++;
		}
		ptr[top]=item;
		top++;
	}
	else	//여분 자리가 있을경우
	{
		ptr[top]=item;
		top++;
	}
	return true;
}

// 스택에서 pop하여 그 값을 item으로 가져오는 함수(성공하면 true, 실패하면 false 반환) 
bool pop(int & item)
{
	if (top > 0)
	{
	item=ptr[top-1];
	ptr[top]=NULL;
	top--;
	return true;
	}
	else
		return false;
}

// 스택에 들어있는 데이터 개수(배열에 들어있는 원소 개수)를 반환 
int length() const
{
	return top;	// top이 데이터 개수이다
}

// 스택이 가지고 있는 동적배열의 크기를 반환 
int getSize() const
{
	return size;
}
}; 

int main()
{
	MyStack s, t(9), u(16);

	cout << "스택 s의 내부 동적배열 크기는 " << s.getSize() << "입니다.\n";
	cout << "스택 t의 내부 동적배열 크기는 " << s.getSize() << "입니다.\n";
	cout << "스택 u의 내부 동적배열 크기는 " << s.getSize() << "입니다.\n\n\n";

	cout << "스택 s에 17개의 데이터를 push 합니다.\n\n";
	for (int i=1; i<= 17; i++) {
		if (s.push(i))
			cout << "push(" << i << "), 스택의 데이터 개수 = " << s.length() << ", 스택내부 동적배열 크기 = " << s.getSize() << endl;
	}
	cout << "\n\n";
	cout << "스택 s로부터 17개의 데이터를 pop 합니다.\n\n";
	for (int i=1; i<= 17; i++) {
		int n;
		if (s.pop(n))
			cout << "pop(" << n << "), 스택의 데이터 개수 = " << s.length() << ", 스택내부 동적배열 크기 = " << s.getSize() << endl;
	}
	cout << "\n\n";

	return 0;
}

//객체지향 Stack 구조 구현
//분석 필수!