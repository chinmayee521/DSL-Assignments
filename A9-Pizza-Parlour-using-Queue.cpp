//============================================================================
// Name        : pizzaaa.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include<iostream>
using namespace std;

typedef struct pizza
{
	int cust_id;
    int item[5];
	int qty[5];
	int cost[5];
	int Bill;
	int cnt;
}pizza;

class pizza_parlor
{
	pizza p[10]; //queue
	int front, rear;
	int count;
public:
	pizza_parlor()
{
		front=-1;
		rear=-1;
		count=0;

}

	int isempty()
	{
		if ( front==-1)
			return 1;
		else
			return 0;
	}
	int isfull()
	{
		if((rear+1)%10==front)
			return 1;
		else
			return 0;
	}
void init()
{
	front=-1;
	rear=-1;
}
	void placeorder()
	{
		if(isfull())
		{
			cout<<" full ";
			return;
		}
		else
		{
			if(isempty())
			{
				front=(front+1)%10;
			}
			rear=(rear+1)%10;
			p[rear].Bill=0;
			cout<< " enter customer id : ";
			cin>>p[rear].cust_id;
			cout<<"enter total no. of items";
			cin>>p[rear].cnt;
			for(int i=0; i<p[rear].cnt;i++)
			{
				cout<< "\n1.Veg Pizza \n2.Cheese Pizza \n3.Paneer Pizza \n4.other \n";
				cout<<"\nEnter ur option";
				cin>>p[rear].item[i];
				if(p[rear].item[i]==1)
					p[rear].cost[i]=150;
				else if(p[rear].item[i]==2)
					p[rear].cost[i]=200;
				else if(p[rear].item[i]==3)
				p[rear].cost[i]=250;
				else
					p[rear].cost[i]=300;
				cout<<"Enter quantity";
				cin>>p[rear].qty[i];
			}
			count++;
		}
	}

	void serveorder()
	{
		if(isempty())
		{
			cout<< "No orders";
			return;
		}
		else
		{
int k=front;
			for(int i=0; i<p[k].cnt;i++)
			{
				p[k].Bill= p[k].Bill + (p[k].cost[i] * p[k].qty[i]);
			}
			cout<< "Customer Id : "<< p[front].cust_id << " order is served and "<< p[front].Bill << "  is paid. Thank you. Visit Again ..\n\n " ;
			if(front==rear)
			{
				init();
			}
			else
			{
			front=(front+1)%10;}
		}
		count--;
	}
	void displyorder()
	{
		cout<< " Total orders are : \n ";
		int i=0;
		int j=front;
		while(i<count)
		{
			cout<< p[j].cust_id <<"\t";
			j=(j+1)%10;
			i++;
		}
	}
	void Ready(){
		cout<< "Customer ID : "<< p[front].cust_id << " Your Order Will get Ready Soon \n\n";
	}
};
int main()
{
	pizza_parlor A;
	int ch;
	char c;
	do
	{
	cout<< "\n 1.Place Order \n 2.ServeOrder\n 3.Display Queue\n 4.Next Oder\n ";
	cout<< " \nEnter your choice :  ";
	cin>>ch;
	switch(ch)
	{
	case 1: A.placeorder();
		break;
	case 2: A.serveorder();
	break;
	case 3: A.displyorder();
	break;
	case 4: A.Ready();
	break;
	}
	cout<< " Continue";
	cin>>c;
	}while(c=='y');
	return 0;
}
