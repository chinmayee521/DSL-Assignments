//============================================================================
// Name        : Assignment.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
  
/*Write C++ program to store marks scored for first test of subject ‘Data structure and Algorithm’ for n students compute
    i)Average score of class
    ii)Highest score and lowest score of class.
    iii)marks scored by most of the students.
    iv)list of students who were absent for the test.
*/
#include <iostream>
using namespace std;
class student
{
	int rollno; int marks;
	string name;
	char att;
	int max, min, sum, i;
public:
    static int avg;
	static int fcnt[31];
	static int maxrange;
	static int count;

    void accept();
	void display();
	int maximum(int max);
	int minimum(int min);
    void average();
    void absent();


};
int student::avg;
int student::fcnt[31];
int student::maxrange;
int student::count;


void student::accept()
{

	cout<<"\nEnter the Name of student:";
	cin>>name;
	cout<<"\nEnter the Roll number of student:";
	cin>>rollno;
	cout<<"\nAttendance-Present(p) or Absent(a):";
			cin>>att;

	if(att=='p')
	{
		student::count++;
		cout<<"\nEnter the Marks of student in DSA(out of 30):";
		d:cin>>marks;
		if(marks>30)
		{
			cout<<"\nInvalid marks, enter again:";
			goto d;
		}
		student::fcnt[marks]++;

	}
	else
	{
		marks=-1;
	}

}
void student::display()
{
	if(att=='p')
	{
		cout<<"\n\t"<< rollno<<"\t"<<name<<"\t"<<marks<<"\t"<<"Present";
	}
	else
	{
		cout<<"\n\t"<< rollno<<"\t"<<name<<"\t"<<marks<<"\t"<<"Absent";
	}
}
int student::maximum(int max)
{
	if(marks>max)
		max=marks;
	return(max);
}
int student::minimum(int min)
{
	if(att=='p' && marks<min)
		min=marks;
	return(min);
}
void student::average()
{

	if(att=='p')
	{
		student::avg=student::avg+marks;
	}


}
void student:: absent()
{
	if(att=='a')
		cout<<rollno<<" \t "<<name<<endl;

}


int main()
{

	int n,max=0,min=101;
	student::avg=0;
	cout<<"Enter the number of students-";
	cin>>n;
	student s[n];
	for(int i=0;i<n;i++)
		s[i].accept();
	cout<<"***STUDENT DATABASE IS AS FOLLOWS***";
	cout<<"\n    ROLL NO.\tNAME \tMARKS \tATTENDANCE";
	for(int i=0;i<n;i++)
		s[i].display();
	for(int i=0;i<n;i++)
		max=s[i].maximum(max);
	cout<<"\nHighest score in class:"<<max;
	for(int i=0;i<n;i++)
		min=s[i].minimum(min);
	cout<<"\nLowest score in class:"<<min;
	for(int i=0;i<n;i++)
	 s[i].average();
	cout<<"\nAverage marks are:"<<student::avg/student::count;
	cout<<"\nList of absent students is as follows:\n";
	cout<<"Rollno\tNAME\n";
	for(int i=0;i<n;i++)
		s[i].absent();
	cout<<"\nFrequency count of marks scored by students:";
	cout<<"\n\nMarks\t\tCount";
		for(int i=0;i<30;i++)
		{
			if(student::maxrange<student::fcnt[i])
			{
				student::maxrange=student::fcnt[i];
				cout<<student::maxrange;
			}
		}
		for(int i=0;i<31;i++)
		{
			if(student::fcnt[i]==student::maxrange)
				cout<<"\n"<<i<<"\t\t"<<student::fcnt[i];
		}

	return 0;
}







/*OUTPUT:
Enter the number of students-5

Enter the Name of student:a

Enter the Roll number of student:1

Attendance-Present(p) or Absent(a):p

Enter the Marks of student in DSA(out of 30):13

Enter the Name of student:b

Enter the Roll number of student:2

Attendance-Present(p) or Absent(a):p

Enter the Marks of student in DSA(out of 30):15

Enter the Name of student:c

Enter the Roll number of student:3

Attendance-Present(p) or Absent(a):a

Enter the Name of student:d

Enter the Roll number of student:4

Attendance-Present(p) or Absent(a):p

Enter the Marks of student in DSA(out of 30):22

Enter the Name of student:e

Enter the Roll number of student:5

Attendance-Present(p) or Absent(a):a
***STUDENT DATABASE IS AS FOLLOWS***
    ROLL NO.	NAME 	MARKS 	ATTENDANCE
	1	         a	     13	     Present
	2	         b	     15	     Present
	3	         c	     -1	     Absent
	4	         d	     22	     Present
	5	         e	     -1    	 Absent
Highest score in class:22
Lowest score in class:13
Average marks are:16
List of absent students is as follows:
Rollno	 NAME
  3 	   c
  5 	   e

Frequency count of marks scored by students:

Marks		Count1
13		    1
15		    1
22		    1 */
