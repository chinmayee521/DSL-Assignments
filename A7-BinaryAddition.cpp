//============================================================================
// Name        : Assignment.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
typedef struct node
{

	node *next;
	node *prev;
	int data;

}node;
class binary
{
	node *hn,*cn;
	int carry,sum;
public:
	void create();
	void display();
	void ones_comp();
	void add(binary b1,binary b2);
	int addnode(int, int);
	void ones_complement(binary b1);
	void twos_complement(binary b1);
	binary()
	{
		hn=NULL;
	}
};
void binary::create()
{
	char ch;

	node *nn;

	do
	{
		nn=new node;
	cout<<"\nEnter the bit:";
	cin>>nn->data;
	if(nn->data!=1 && nn->data!=0)
	{
		cout<<"\nINVALID BINARY INPUT";
		cout<<"\nEnter valid binary bit:";
		cin>>nn->data;
	}
	nn->next=NULL;
	nn->prev=NULL;
	if(hn==NULL)
	{
		hn=nn;
	}
	else
	{
		node *cn;
		cn=hn;
		while(cn->next!=NULL)
		{
			cn=cn->next;
		}
		cn->next=nn;
		nn->prev=cn;
	}
	cout<<"\nContinue(y/n)?";
	cin>>ch;
	}while(ch=='y');
}
void binary::display()
{
	node *cn;
	cn=hn;
	cout<<"\nThe binary number is";
	while(cn->next!=NULL)
	{

		cout<<cn->data<<" ";
		cn=cn->next;
	}
	cout<<cn->data;
}
int binary::addnode(int sum,int carry)
{


	node *nn=new node;
    nn->data=sum%2;
    carry=sum/2;
	nn->next=NULL;
	nn->prev=NULL;
	if(hn==NULL)
	{
		hn=nn;
	}
	else
	{
		hn->prev=nn;
		nn->next=hn;
		hn=nn;
	}
	return carry;

}

void binary::add(binary b1, binary b2)
{


	int carry=0,sum;
	node *cn1=b1.hn;
	node *cn2=b2.hn;
	for(cn1=b1.hn;cn1->next!=NULL;cn1=cn1->next);
		for(cn2=b2.hn;cn2->next!=NULL;cn2=cn2->next);

			while(cn1!=NULL && cn2!=NULL)
			{
				sum=cn1->data+cn2->data+carry;

				carry=addnode(sum,carry);
				cn1=cn1->prev;
				cn2=cn2->prev;
			}
	while(cn1!=NULL)
	{

		sum=(cn1->data+carry);

		carry=addnode(sum,carry);
		cn1=cn1->prev;
	}
	while(cn2!=NULL)
		{

			sum=(cn2->data+carry);

			carry=addnode(sum,carry);
			cn2=cn2->prev;
		}
			if(carry==1)
			{
				sum=1;
				addnode(sum,carry);

			}

}
void binary::ones_complement(binary b1)
{	node *nn1=new node;

	node *cn=new node;
	cn=b1.hn;
	nn1=hn;
while(cn!=NULL)
{
	node *nn=new node;
	nn->next=NULL;
		nn->prev=NULL;
		if(cn->data==1)
		{
			nn->data=0;
		}
		else
		{
			nn->data=1;
		}
		if(hn==NULL)
		{
			hn=nn;

		}
		else
		{
			nn1=hn;
			while(nn1->next!=NULL)
			{
				nn1=nn1->next;
			}
			nn1->next=nn;
			nn->prev=nn1;
		}
		 cn=cn->next;
}

}
void binary::twos_complement(binary b1)
{
	node *cn=new node;
	for(b1.cn = b1.hn;b1.cn!=NULL;b1.cn=b1.cn->next)
		{
			node * nn;
			nn = new node;
			if(b1.cn->data==0)
			{
				nn->data = 1;
			}
			else
			{
				nn->data =0;
			}
			if(hn==NULL)
			{
				hn = nn;
				nn->next = nn->prev =NULL;
				cn = nn;
			}
			else
			{
				cn->next = nn;
				nn->prev=cn;
				cn=nn;
				nn->next = NULL;
			}
		}
		while(cn!=NULL)
		{
			if(cn->data == 0)
			{
				cn->data = 1;
				break;
			}
			else
			{
				cn->data = 0;
				cn = cn->prev;
			}
		}
		if(cn == NULL)
		{

			node * nn;
			nn = new node;
			cn = hn;
			hn = nn;
			nn->data = 1;
			cn->prev = nn;
			nn->prev = NULL;
			nn->next = cn;
		}









}
int main()
{
	binary b1, b2, a,b,c;
	cout<<"\nEnter 1st binary number";
	b1.create();
	b1.display();
	cout<<"\nEnter 2nd binary number";
	b2.create();
	b2.display();
	int n;
	char sel;
	do
	{
	cout<<"\n1)ADDITION \t 2)ONES COMPLEMENT \t 3)TWOS COMPLEMENT";
	cin>>n;
	switch (n)
	{
	case 1:

	cout<<"\nAddition of the binary numbers is:";
	a.add(b1,b2);
	a.display();
	break;

	case 2:
	cout<<"\nOne's complement: ";
	b.ones_complement(b1);
	b.display();
	break;

	case 3:
	cout<<"\nTwo's complement: ";
	c.twos_complement(b1);
	c.display();
	break;
	default:
		cout<<"\nINVALID";
		break;
	}
	cout<<"\nDo you want to continue?(y/n)";
	cin>>sel;
	}while(sel=='y'|| sel=='Y');
	return 0;
}



/*
 * OUTPUT:
 Enter 1st binary number
Enter the bit:1

Continue(y/n)?y

Enter the bit:0

Continue(y/n)?y

Enter the bit:1

Continue(y/n)?y

Enter the bit:1

Continue(y/n)?n

The binary number is1 0 1 1
Enter 2nd binary number
Enter the bit:1

Continue(y/n)?y

Enter the bit:0

Continue(y/n)?y

Enter the bit:1

Continue(y/n)?n

The binary number is1 0 1
1)ADDITION 	 2)ONES COMPLEMENT 	 3)TWOS COMPLEMENT1

Addition of the binary numbers is:
The binary number is1 0 0 0 0
Do you want to continue?(y/n)y

1)ADDITION 	 2)ONES COMPLEMENT 	 3)TWOS COMPLEMENT2

One's complement:
The binary number is0 1 0 0
Do you want to continue?(y/n)y

1)ADDITION 	 2)ONES COMPLEMENT 	 3)TWOS COMPLEMENT3

Two's complement:
The binary number is0 1 0 1
Do you want to continue?(y/n)n

 */
