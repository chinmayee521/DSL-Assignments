//============================================================================
// Name        : Assignment.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/* Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of
Second, third and final year of department can be granted membership on request. Similarly one may
cancel the membership of club. First node is reserved for president of club and last node is reserved for
secretary of club. Write C++ program to maintain club members information using singly linked list.
Store student PRN and Name. Write functions to
	a)Add and delete the members as well as president or even secretary.
	b)Compute total number of members of club .
	b)Display members .
	c)Display list in reverse order using recursion .
	e)Two linked lists exists for two divisions. Concatenate two lists.
*/
#include <iostream>
using namespace std;
typedef struct node
{
	string name, prn, post;
	struct node *next;
}node;
class pinnacle_club
{
	int count;
	node *hn, *ln;
public:
	pinnacle_club()
{
	hn=NULL;
	ln=NULL;
	count=0;
}
	void create();
	void display();
	void insert();
	void del();

	void concat(pinnacle_club l2);
	void reverse_display(node *);			//using recursion
		node * return_head()
		{						// function to return head .. for recursion function
			return hn;
		}
};
void pinnacle_club::create()
{
	node *nn;
		char ch;
		do
		{
			count++;
			nn=new node;
			cout<<"\nEnter name, PRN number:";
			cin>>nn->name>>nn->prn;
			nn->next=NULL;
			if(hn==NULL)
			{
				hn=nn;
				ln=nn;
			}
			else
			{
				ln->next=nn;
				ln=nn;
			}
			cout<<"\nDo you want to add new members (y/n)?";
			cin>>ch;

		}while(ch=='y');


}
void pinnacle_club::display()
{
	node *cn=hn;

		while(cn->next!=NULL)
		{
			if(cn==hn)
			{
			cout<<"\n"<<cn->name<<"\t  "<<cn->prn<<"\t\t president";
			}
			else
			{
				cout<<"\n"<<cn->name<<"\t  "<<cn->prn<<"\t\t member";
			}
			cn=cn->next;
		}
		cout<<"\n"<<cn->name<<"\t  "<<cn->prn<<"\t\t secretary";

		cout<<"\nTotal number of students in Pinnacle Club="<<count;

}
void pinnacle_club::insert()
{
	char c;
	node *nn=new node;
	node *cn=new node;
	cout<<"\nEnter name and prn number of student to be added in the club: ";
	cin>>nn->name>>nn->prn;
	nn->next=NULL;
	cout<<"P to add a PRESIDENT, M to add a MEMBER, S to add a SECRETARY ";
	cin>>c;
	if(c=='p'||c=='P')
	{
		cn=hn;
		nn->next=cn;
		hn=nn;
      count++;
	}
	else if(c=='s'||c=='S')
	{
		cn=ln;
		cn->next=nn;
		ln=nn;
      count++;
	}
	else if(c=='m' || c=='M')
	{
		string key;
		cout<<"\n Enter the PRN number of the member after whom you want to add a new member:  ";
		cin>>key;
		for(cn=hn;cn->prn!=key;cn=cn->next);
			nn->next=cn->next;
			cn->next=nn;
         count++;


	}
	display();
}
void pinnacle_club::del()
{
	string d;
	node *cn=new node;
	cout<<"\n Enter PRN number of student to be deleted";
	cin>>d;
	cn=hn;
	do
	{
		if(cn->prn==d)
		{
			hn=cn->next;
            count--;

			break;

		}
		else if(cn->next==ln && cn->next->prn==d)
		{
			cn->next=NULL;
			ln=cn;
			count--;

			break;


		}
		else if(cn->next->prn==d && cn->next!=ln)
			{
			cn->next=cn->next->next;
			count--;

			break;
			}
			cn=cn->next;
	}while(cn->next!=NULL);
	display();
}
void pinnacle_club::concat(pinnacle_club l2)
{
	node *cn;

	if(hn==NULL)
	{
		hn=l2.hn;
	}
	else if(l2.hn==NULL)
	{}
	else
	{

			for(cn= hn;cn->next!=NULL;cn=cn->next);

			cn->next = l2.hn;

			for(cn = hn;cn->next!=NULL;cn=cn->next);
			ln = cn;
			}
	count=count+l2.count;

	}





void pinnacle_club ::reverse_display( node *cn)
{
	if(cn!= NULL)
	{
		reverse_display(cn->next);
		cout<<"\n"<<cn->name<<"\t"<<cn->prn;
	}
}

int main()
{
	pinnacle_club l1,l2;
		node *hn;
		hn=NULL;


	char k;





    cout<<"\nEnter the information of students of DIVISION A in PINNACLE CLUB:";
    l1.create();
    cout<<"\n***DIVISION A--List of students in Pinnacle Club***";
    l1.display();
    char choice;
    do
    {
    int sel;
    cout<<"\n1)To add member\t2)To delete member\t3)To reverse";
    cin>>sel;
    switch(sel)
    {
    case 1:
    l1.insert();
    break;
    case 2:
    l1.del();
    break;
    case 3:
    	cout<<"\n Reverse of l1 ::";
    			node*a=l1.return_head();
    			l1.reverse_display( a);

    			break;


    }
    cout<<"\nDo you want to continue(y/n)";
    cin>>choice;
    }while(choice=='y' || choice=='Y');






    cout<<"\nEnter the information of students of DIVISION B in PINNACLE CLUB:";
    l2.create();
    cout<<"\n***DIVISION B--List of students in Pinnacle Club***";
    l2.display();
    char x;
        do
        {
        int s;
        cout<<"\n1)To add member\t2)To delete member\t3)To reverse";
        cin>>s;
        switch(s)
        {
        case 1:

        l2.insert();
        break;
        case 2:
        l2.del();
        break;
        case 3:
        	cout<<"\n Reverse of l2 ::";
        	    			node *b=l2.return_head();
        	    			l2.reverse_display(b);
    	break;
        }
        cout<<"\nDo you want to continue(y/n)";
        cin>>x;
        }while(x=='y' || x=='Y');




cout<<"\nConcatenated list:";
l1.concat(l2);
l1.display();

	return 0;
}


/* OUTPUT:
 * Enter the information of students of DIVISION A in PINNACLE CLUB:
Enter name, PRN number:a
1

Do you want to add new members (y/n)?y

Enter name, PRN number:b
2

Do you want to add new members (y/n)?y

Enter name, PRN number:c
3

Do you want to add new members (y/n)?n

***DIVISION A--List of students in Pinnacle Club***
a	  1		 president
b	  2		 member
c	  3		 secretary
Total number of students in Pinnacle Club=3
1)To add member	2)To delete member	3)To reverse1

Enter name and prn number of student to be added in the club: d
4
P to add a PRESIDENT, M to add a MEMBER, S to add a SECRETARY s

a	  1		 president
b	  2		 member
c	  3		 member
d	  4		 secretary
Total number of students in Pinnacle Club=4
Do you want to continue(y/n)y

1)To add member	2)To delete member	3)To reverse3

 Reverse of l1 ::
d	4
c	3
b	2
a	1
Do you want to continue(y/n)n

Enter the information of students of DIVISION B in PINNACLE CLUB:
Enter name, PRN number:e
5

Do you want to add new members (y/n)?y

Enter name, PRN number:f
6

Do you want to add new members (y/n)?y

Enter name, PRN number:g
7

Do you want to add new members (y/n)?y

Enter name, PRN number:h
8

Do you want to add new members (y/n)?n

***DIVISION B--List of students in Pinnacle Club***
e	  5		 president
f	  6		 member
g	  7		 member
h	  8		 secretary
Total number of students in Pinnacle Club=4
1)To add member	2)To delete member	3)To reverse2

 Enter PRN number of student to be deleted8

e	  5		 president
f	  6		 member
g	  7		 secretary
Total number of students in Pinnacle Club=3
Do you want to continue(y/n)y

1)To add member	2)To delete member	3)To reverse3

 Reverse of l2 ::
g	7
f	6
e	5
Do you want to continue(y/n)n

Concatenated list:
a	  1		 president
b	  2		 member
c	  3		 member
d	  4		 member
e	  5		 member
f	  6		 member
g	  7		 secretary
Total number of students in Pinnacle Club=7
 */
