#include<iostream>

using namespace std;

int top = -1;
int m = 4;
int stack[4];

int is_empty()
{
	if (top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int is_full()
{
	if(top == m)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int push(int a)
{
	if(!is_full())
	{
		top += 1;
		stack[top] = a;
	}
	else
	cout<<"stack is full"<<endl;
}

int pop()
{
	if(! is_empty())
	{
		int data;
		data = stack[top];
		top -= 1;
		cout<<"the popped element is"<<data;
	}
	else
	cout<<"stack is empty"<<endl;
}

int main()
{
	push(5);
	push(10);
	push(300);
	push(25);
	pop();
	pop();
	pop();
	pop();
	pop();
}
