//============================================================================
// Name        : A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;
#define size 5
class deque
{
	int a[size],front, rear, data;
public:
	deque()
	{
		front=-1;
		rear=-1;
		data=0;
	}
	int empty();
	int full();
	void accept();
	void enqueue_f();
	void enqueue_r();
	void del_f();
	void del_r();
	void display();
};



int deque::empty()
{
	if(front==-1 && rear==-1)
	{
		return 1;
	}
	else
		return 0;
}

int deque::full()
{
	if(rear==size-1)
	{
		return 1;
	}
	else
		return 0;
}

void deque::enqueue_f()
{
	if(!full())
	{
		cout<<"\nEnter data to insert at front: ";
		cin>>data;
		if(empty())
		{
			rear++;
			front++;
			a[front]=data;
		}
		else
		{
			for(int i=rear;i>=front;i--)
			{
				a[i+1]=a[i];
			}

				a[front]=data;
				rear++;

		}
		cout<<"\nFront:"<<front<<"\tRear:"<<rear;
	}
	else
		cout<<"\nFULL";
}

void deque::enqueue_r()
{
	int d;

	if(!full())
	{
		cout<<"\nEnter data to insert at rear";
			cin>>d;
			if(empty())
			{
				rear++;
				front++;
				a[front]=d;
			}
			else
			{
				rear++;
				a[rear]=d;
			}
			cout<<"\nFront:"<<front<<"\tRear:"<<rear;

	}
	else
		cout<<"\nFULL";
}

void deque::del_f()
{
	if(!empty())
	{
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
			front++;

	}
	else
		cout<<"\nEMPTY";
	cout<<"\nFront:"<<front<<"\tRear:"<<rear;
}

void deque::del_r()
{
	if(!empty())
	{
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
			rear--;
	}
	else
		cout<<"\nEMPTY";
	cout<<"\nFront:"<<front<<"\tRear:"<<rear;
}
void deque::display()
{
	if(empty())
		cout<<"\nEmpty!!";
	else
	{
	for(int i=front;i<=rear;i++)
	{
		cout<<a[i]<<" ";
	}
	}
}


int main()
{
	int n;
	deque d;
	do
	{
	cout<<"\n***menu***\n\n 1)Insert front\t 2)Insert rear\t 3)Delete front\t 4)Delete rear\t 5)Display\t 6)Exit\n  ";
	cout<<"\nEnter choice:";
	cin>>n;
	switch(n)
	{
	case 1:
		d.enqueue_f();
		break;

	case 2:
		d.enqueue_r();
		break;

	case 3:
	    d.del_f();
	    break;

	case 4:
		d.del_r();
		break;

	case 5:
		d.display();
		break;


	}


	}while(n!=6);



	return 0;
}
