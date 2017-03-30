#include <iostream>
using namespace std;

class MyStack { 
private: 
	int * ptr;
	int size;
	int top;
public: 
// ������ ������ ���� �������� ũ�Ⱑ 8�� �����迭�� ����� ������ 
MyStack()
{
	ptr=new int[8];
	size=8;
	top=0;
	cout<<"*** DEBUG *** MyStack::MyStack()���� new�� �̿��Ͽ� ũ�� "<<size<<"�� �����迭�� �޸𸮸� �Ҵ�"<<endl;
}

// ������ ������ ���� �������� ũ�Ⱑ s���� �������� �ּ��� 8�� ����� �����迭�� ����� ������ (��: s == 9 �� ���� s == 16 �� ��� ��� ũ�Ⱑ 16�� �����迭 ����) 
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
	cout<<"*** DEBUG *** MyStack::MyStack(int s)���� new�� �̿��Ͽ� ũ�� "<<size<<"�� �����迭�� �޸𸮸� �Ҵ�"<<endl;
}

MyStack(const MyStack & stack) // ���������, 5�� 8�� �����ð��� ���� ����, �ٸ� �κк��� ���� ������ �� 
{
	ptr=new int[stack.size];
	cout<<"*** DEBUG *** MyStack::push(int item)���� new�� �̿��Ͽ� ũ�� "<<stack.size<<"�� �����迭�� �޸𸮸� �Ҵ�"<<endl;
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

// �����迭�� �����ϴ� �Ҹ��� 
~MyStack()
{
	if ( ptr != NULL )
	{
		delete[]ptr;
		cout<<"*** DEBUG *** MyStack::~MyStack()���� delete�� �̿��Ͽ� ũ�� "<<size<<"�� �����迭�� �޸𸮸� ��ȯ"<<endl;
	}
}

// item ���� ���ÿ� push�ϴ� �Լ�(�����ϸ� true, �����ϸ� false ��ȯ) 
// �迭�� ������ �����ϸ�: ���� �迭ũ���� 2���� �� �迭�� new�� �Ҵ���� 
// -> ���� �����͸� �� �迭�� �����ϰ� item ���� �����Ϳ� �߰� -> ���� �迭�� delete�ϰ� �� �迭�� �̿��� 
bool push(int item)
{
	if ( size == top )	// �迭�� ��� �����Ͱ� �� ���������, 2���� ���迭�� new�� �޾ƾ��Ѵ�.
	{
		MyStack temp(*this);
		delete[]ptr;
		cout<<"*** DEBUG *** MyStack::push(int item)���� delete�� �̿��Ͽ� ũ�� "<<size<<"�� �����迭�� �޸𸮸� ��ȯ"<<endl;
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
	else	//���� �ڸ��� �������
	{
		ptr[top]=item;
		top++;
	}
	return true;
}

// ���ÿ��� pop�Ͽ� �� ���� item���� �������� �Լ�(�����ϸ� true, �����ϸ� false ��ȯ) 
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

// ���ÿ� ����ִ� ������ ����(�迭�� ����ִ� ���� ����)�� ��ȯ 
int length() const
{
	return top;	// top�� ������ �����̴�
}

// ������ ������ �ִ� �����迭�� ũ�⸦ ��ȯ 
int getSize() const
{
	return size;
}
}; 

int main()
{
	MyStack s, t(9), u(16);

	cout << "���� s�� ���� �����迭 ũ��� " << s.getSize() << "�Դϴ�.\n";
	cout << "���� t�� ���� �����迭 ũ��� " << s.getSize() << "�Դϴ�.\n";
	cout << "���� u�� ���� �����迭 ũ��� " << s.getSize() << "�Դϴ�.\n\n\n";

	cout << "���� s�� 17���� �����͸� push �մϴ�.\n\n";
	for (int i=1; i<= 17; i++) {
		if (s.push(i))
			cout << "push(" << i << "), ������ ������ ���� = " << s.length() << ", ���ó��� �����迭 ũ�� = " << s.getSize() << endl;
	}
	cout << "\n\n";
	cout << "���� s�κ��� 17���� �����͸� pop �մϴ�.\n\n";
	for (int i=1; i<= 17; i++) {
		int n;
		if (s.pop(n))
			cout << "pop(" << n << "), ������ ������ ���� = " << s.length() << ", ���ó��� �����迭 ũ�� = " << s.getSize() << endl;
	}
	cout << "\n\n";

	return 0;
}

//��ü���� Stack ���� ����
//�м� �ʼ�!