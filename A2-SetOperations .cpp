//============================================================================
// Name        : Assignment.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
  
/*SET Operations
*/

#include<iostream>
using namespace std;
class setop
{
int i,flag,rno[20];
char name[20];
int count;
public:
	setop()
	{
	i=0;
	count=0;
	flag=0;
	}

	void accept()
{

	cin>>count;

	for(i=0;i<count;i++)
	{
	cout<<"\nEnter roll number of student:";
	cin>>rno[i];

	cout<<"\nEnter name of student:";
	cin>>name[i];
	}
}
	void display()
{
	cout<<"{";
	for(i=0;i<count;i++)
	{
	cout<<rno[i]<<"-"<<name[i];
	if (i<count-1)
	cout<<",";
	}
	cout<<"}";
}

//either cricket or badminton

	int funion(setop A,setop B)
	{
	for (int i=0;i<A.count;i++)
	{
	rno[i]=A.rno[i];
	name[i]=A.name[i];
	count++;
	}

	for (int i=0;i<B.count;i++)
{
	flag=0;

	for (int j=0;j<A.count;j++)
	{
	if (B.rno[i]==A.rno[j])
		{
		flag=1;
		break;
		}
	}

	if (flag==0)
	{
	rno[count]=B.rno[i];
	name[count]=B.name[i];
	count++;
	}
}
	//cout<<count;
return count;

}
	//both cricket and badminton

	void fintersection(setop A,setop B)
{
     for (int i=0;i<A.count;i++)
     {
      for (int j=0;j<B.count;j++)
       {
            if (A.rno[i]==B.rno[j])
            {
              rno[count]=A.rno[i];
              name[count]=A.name[i];
              count++;
              break;
            }
        }
     }
}
	//only cricket or only badminton

	void fdifference(setop A,setop B)
{

for (int i=0;i<A.count;i++)
{
for (int j=0;j<B.count;j++)

{
if (A.rno[i]==B.rno[j])
{
flag=0;
break;
}

else

{

flag=1;

}

}
if(flag==1)
{
rno[count]=A.rno[i];
name[count]=A.name[i];
count++;
}

}

}
};

	int main()
{
//int count;
int m,l;
int ch;
char z;

cout<<"\nEnter total number of students in SE Computer";
cin>>m;

setop A,B,D,E,F,G;

cout<<"\nEnter number of students who play cricket"<<endl;
A.accept();

cout<<"\nEnter number of students who play badminton"<<endl;
B.accept();

cout<<"\nStudents who play CRICKET: ";
A.display();

cout<<"\nStudents who play BADMINTON: ";
B.display();

	do
{
cout<<"\n\n1-Union \t 2-Intersection \t 3-Only cricket \t 4-Only badminton \t 5-None"<<endl;
	cout<<"\nEnter your choice";
	cin>>ch;
	switch(ch)
	{
case 1:
	cout<<"\nStudents who play either cricket or badminton or both: ";
	l=D.funion(A,B);
	D.display();
break;

	case 2:
cout<<"\nStudents who play both cricket and badminton: ";
E.fintersection(A,B);
E.display();
break;

	case 3:
cout<<"\nStudents who play only cricket are (A-B): ";
F.fdifference(A,B);
F.display();
break;

	case 4:
cout<<"\nStudents who play only badminton are(B-A): ";
G.fdifference(B,A);
G.display();
break;

	case 5:
		int n;
		n=m-l;

cout<<"\nNo. of students who play neither cricket nor badminton: "<<n;
break;

	default:
cout<<"Invalid choice";
break;
	}
	cout<<"\nAny other choice?(y/n)";
	cin>>z;
}while(z=='y' || z=='Y');

return 0;

}


	/* OUTPUT:
	 Enter total number of students in SE Computer10

Enter number of students who play cricket
3

Enter roll number of student:1

Enter name of student:c

Enter roll number of student:2

Enter name of student:m

Enter roll number of student:3

Enter name of student:n

Enter number of students who play badminton
2

Enter roll number of student:1

Enter name of student:c

Enter roll number of student:4

Enter name of student:g

Students who play CRICKET: {1-c,2-m,3-n}
Students who play BADMINTON: {1-c,4-g}

1-Union 	 2-Intersection 	 3-Only cricket 	 4-Only badminton 	 5-None

Enter your choice1

Students who play either cricket or badminton or both: {1-c,2-m,3-n,4-g}
Any other choice?(y/n)y


1-Union 	 2-Intersection 	 3-Only cricket 	 4-Only badminton 	 5-None

Enter your choice2

Students who play both cricket and badminton: {1-c}
Any other choice?(y/n)y


1-Union 	 2-Intersection 	 3-Only cricket 	 4-Only badminton 	 5-None

Enter your choice3

Students who play only cricket are (A-B): {2-m,3-n}
Any other choice?(y/n)y


1-Union 	 2-Intersection 	 3-Only cricket 	 4-Only badminton 	 5-None

Enter your choice4

Students who play only badminton are(B-A): {4-g}
Any other choice?(y/n)y


1-Union 	 2-Intersection 	 3-Only cricket 	 4-Only badminton 	 5-None

Enter your choice5

No. of students who play neither cricket nor badminton: 6
Any other choice?(y/n)n */
