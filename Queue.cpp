#include<iostream>

using namespace std;

void push(int val, int arr[10], int &rear)
{
	arr[rear] = val;
	rear++;
}


void pop(int &front, int arr[10])
{
	cout<<"Popped value is "<<arr[front]<<endl;
	arr[front] = 0;
	front++;
}


void show(int arr[10], int front, int rear)
{
	for(int i = front; i < rear; i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}


int main()
{
	int arr[10], front = 0, rear = 0, val, max = 5;
	char c = 'y';
	while(c == 'y')
	{
		if(rear < max)
		{
			cout<<"Enter value to push"<<endl;
			cin>>val;
			push(val, arr, rear);
			cout<<"Do you want to add more values? (y / n)";
			cin>>c;
			cout<<endl;	
		}
		else
		{
			cout<<"Queue Overflow"<<endl;
			c = 'n';
		}	
	}
	
	cout<<"Do you want to pop a value? (y / n)";
	cin>>c;
	while(c == 'y')
	{
		if(front != rear)
		{
			pop(front, arr);
			cout<<"Do you want to remove more values? (y / n)";
			cin>>c;
			cout<<endl;
		}
		else
		{
			cout<<"Empty Queue"<<endl;
			c = 'n';
		}	
	}
	
	show(arr, front, rear);
}
