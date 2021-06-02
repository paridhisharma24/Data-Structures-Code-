#include<iostream>

using namespace std;

class Node
{
	public:
		int roll;
		Node *next;
		Node(int data)
		{
			roll = data,
			next = NULL;
		}
};

class LL
{
	private:
		Node *top;
		int n = 1;
	public:
		LL()
		{
			top = NULL;
		}
		void LL_insert(int pos, int val)
		{
			Node  *x, *ptr = new Node(val);
			if(pos == 1)
			{
				top = ptr;
				n += 1;
			}
			else 
			{
				while(pos > 1)
				{
					x = top->next;
					pos--;
				}
				ptr->next = x->next;
				x->next = ptr;
				n += 1;
				
			}
		}
		void LL_show()
		{
			Node *ptr = top;
			while(ptr)
			{
				cout<<ptr->roll<<' ';
				ptr = ptr->next;
			}
		}
};


int main()
{
	class LL list;
	list.LL_insert(1, 5);
	list.LL_show();
	list.LL_insert(2, 3);
	list.LL_insert(2, 4);
	list.LL_insert(4, 1);
	list.LL_insert(4, 2);
	list.LL_show();
}
