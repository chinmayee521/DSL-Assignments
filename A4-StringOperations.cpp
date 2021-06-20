//============================================================================
// Name        : Assignment.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<string>
using namespace std;

class String
{
	int len;
public:

/*void display(char c[])

{
	cout<<c;
}*/

int length(char *s)
{
	int i=0;
	while(s[i]!='\0')

	{
	  i++;
	}
return i;
}

void copy(char *a,char *b)
{
	int i=0;
	while(a[i]!='\0')
	{
		b[i]=a[i];
		i++;
	}
	b[i]='\0';
}

void concat(char *a,char *b)
{
	int i=0;
	while(a[i]!='\0')
		i++;
	for(int j=0;b[j]!='\0';j++)
	{
		a[i]=b[j];
		i++;
	}

a[i]='\0';

}

void search(char *a,char *b)
{

	int len=length(b);
	int count,temp,flag=0;
	for(int i=0;a[i]!='\0';i++)
	{
		temp=i;
		count=0;
		for(int j=0;b[j]!='\0';j++)
		{
			if(a[temp]==b[j])
			{
				count++;
			}

			temp++;

			if(count==len)

			{
				cout<<"Substring is present ";
				flag=1;

			}

		}

}

	if(flag==0)

		cout<<"Substring is not present";

}

void reverse(char *a)

{

	int len=length(a);
	char temp;
    int j=len-1;

	for(int i=0;i<(len/2);i++)

	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		j--;

	}

}

void compare(char *a,char *b)

{
	int i=0;

	while(a[i]==b[i] && a[i]!='\0')
		i++;

	if(a[i]>b[i])
		cout<<endl<<a<<" is greater than "<<b<<endl;

	else if(a[i]<b[i])
		cout<<endl<<a<<" is less than "<<b<<endl;

	else
		cout<<"\n"<<a<<" is equal to "<<b<<endl;

}

};

int main()

{
	char str[50],str2[50],z;

	String s1;

	int choice;
do

	{

		cout<<"\nString Operations:\n1.Length\n2.Copy\n3.Concatenate\n4.Search Substring.\n5.Reverse\n6.Compare Strings\n";
        cout<<"\nEnter choice:";
		cin>>choice;

switch(choice)

{

case 1:

cout<<"Enter String:";

cin>>str;

cout<<"\nLength: "<<s1.length(str);

break;

case 2:

cout<<"Enter String:";

cin>>str;

s1.copy(str,str2);

cout<<"Copied String:"<<str2;

break;

case 3:

cout<<"Enter String:";

cin>>str;

cout<<"\nEnter String to concatenate: ";

cin>>str2;

s1.concat(str,str2);

cout<<"\nAfter Concatenate: "<<str;

break;

case 4:

cout<<"Enter String:";

cin>>str;

cout<<"\nEnter String to search: ";

cin>>str2;

s1.search(str,str2);

break;

case 5:

cout<<"Enter String:";

cin>>str;

s1.reverse(str);

cout<<"\nReverse : "<<str;

break;

case 6:

cout<<"Enter String:";

cin>>str;

cout<<"\nEnter another string";

cin>>str2;

s1.compare(str,str2);

break;



}
cout<<"\n Any other choice?(y/n)";
cin>>z;

}while(z=='y' || z=='Y');



return 0;

}


/* OUTPUT:
 String Operations:
1.Length
2.Copy
3.Concatenate
4.Search Substring.
5.Reverse
6.Compare Strings

Enter choice:1
Enter String:pccoe

Length: 5
 Any other choice?(y/n)y

String Operations:
1.Length
2.Copy
3.Concatenate
4.Search Substring.
5.Reverse
6.Compare Strings

Enter choice:2
Enter String:pccoean
Copied String:pccoean
 Any other choice?(y/n)y

String Operations:
1.Length
2.Copy
3.Concatenate
4.Search Substring.
5.Reverse
6.Compare Strings

Enter choice:3
Enter String:pccoe

Enter String to concatenate: college

After Concatenate: pccoecollege
 Any other choice?(y/n)y

String Operations:
1.Length
2.Copy
3.Concatenate
4.Search Substring.
5.Reverse
6.Compare Strings

Enter choice:4
Enter String:string

Enter String to search: ring
Substring is present
 Any other choice?(y/n)y

String Operations:
1.Length
2.Copy
3.Concatenate
4.Search Substring.
5.Reverse
6.Compare Strings

Enter choice:5
Enter String:pccoe

Reverse : eoccp
 Any other choice?(y/n)y

String Operations:
1.Length
2.Copy
3.Concatenate
4.Search Substring.
5.Reverse
6.Compare Strings

Enter choice:6
Enter String:maharashtra

Enter another stringmaha

maharashtra is greater than maha

 Any other choice?(y/n)n
 */




