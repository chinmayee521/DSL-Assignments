//============================================================================
// Name        : Assignment.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;
class sparse
{
	int r,c,nz,sp[10][3];
public:
	void accept();
	void display();
	void addsp(sparse s1, sparse s2);
	void transpose(sparse s1);
	void fast_transpose(sparse s1);
	static int count[10];
	static int pos[10];

};
int sparse::count[10];
int sparse::pos[10];

void sparse::accept()
{
	cout<<"\nEnter the number of rows: ";
	cin>>r;
	cout<<"\nEnter the number of columns: ";
	cin>>c;
	cout<<"\nEnter the number of non zero values: ";
	cin>>nz;
	sp[0][0]=r;
	sp[0][1]=c;
	sp[0][2]=nz;
	for(int i=1;i<=nz;i++)
	{
		cout<<"\nEnter the row number of non zero value:";
		cin>>sp[i][0];
		cout<<"\nEnter the column number of non zero value:";
		cin>>sp[i][1];
		cout<<"\nEnter the non zero value:";
		cin>>sp[i][2];
	}

}
void sparse::display()
{
	cout<<"\n**SPARSE MATRIX**\n\n";
	for(int i=0;i<=nz;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<"\t\t"<<sp[i][j];
		}
		cout<<"\n";
	}
}
void sparse::addsp(sparse s1,sparse s2)
{
	r=s1.r;
	c=s1.c;
	int i=1,j=1,k=1;
	sp[0][0]=r;
	sp[0][1]=c;
	while(i<=s1.nz && j<=s2.nz)
	{
		if(s1.sp[i][0]==s2.sp[j][0])
		{
			if(s1.sp[i][1]==s2.sp[j][1])
			{
				sp[k][0]=s1.sp[i][0];
				sp[k][1]=s1.sp[i][1];
				sp[k][2]=s1.sp[i][2]+s2.sp[j][2];
				i++;
				j++;
				k++;
			}
			else if(s1.sp[i][1]<s2.sp[j][1])
			{
				sp[k][0]=s1.sp[i][0];
				sp[k][1]=s1.sp[i][1];
				sp[k][2]=s1.sp[i][2];
				i++;
				k++;
			}
			else
			{
				sp[k][0]=s2.sp[j][0];
				sp[k][1]=s2.sp[j][1];
				sp[k][2]=s2.sp[j][2];
				j++;
				k++;
			}

		}
		else
		{
			if(s1.sp[i][0]<s2.sp[j][0])
			{
				sp[k][0]=s1.sp[i][0];
				sp[k][1]=s1.sp[i][1];
				sp[k][2]=s1.sp[i][2];
				i++;
				k++;
			}
			else
			{
				sp[k][0]=s2.sp[j][0];
				sp[k][1]=s2.sp[j][1];
				sp[k][2]=s2.sp[j][2];
				j++;
				k++;
			}
		}

	}
	while(i<=s1.nz)
	{
		sp[k][0]=s1.sp[i][0];
		sp[k][1]=s1.sp[i][1];
		sp[k][2]=s1.sp[i][2];
		i++;
		k++;
	}
	while(j<=s2.nz)
	{
		sp[k][0]=s1.sp[j][0];
		sp[k][1]=s1.sp[j][1];
		sp[k][2]=s1.sp[j][2];
		j++;
		k++;
	}
	nz=k-1;
	sp[0][2]=nz;
}

void sparse::transpose(sparse s1)
{int i=1,k=1,j;
nz=s1.sp[0][2];

	sp[0][0]=s1.sp[0][1];
	sp[0][1]=s1.sp[0][0];
	sp[0][2]=s1.sp[0][2];

	for(i=0;i<s1.sp[0][1];i++)
			{
				for(j=1;j<=nz;j++)
				{
					if(i==s1.sp[j][1])
					{
						sp[k][0]=s1.sp[j][1];
						sp[k][1]=s1.sp[j][0];
						sp[k][2]=s1.sp[j][2];
						k++;
					}
				}
			}

}
void sparse::fast_transpose(sparse s1)
{




	    cout<<"\nFast Transpose is =";
	        sp[0][0]=s1.sp[0][1];
	        sp[0][1]=s1.sp[0][0];
	        sp[0][2]=s1.sp[0][2];
	    int p;
	    for(int i=0 ;i<=s1.c ; i++)    // initialize counts to 0
	    {
	        sparse::count[i]=0;

	    }
	    for(int i=1;i<=s1.nz;i++)    // calculating the counts
	    {

	        sparse::count[s1.sp[i][1]]++;

	    }
	    sparse::pos[0]=1;
	    for(int i=1 ;i<=s1.c ;i++ )    //calculating the positions
	    {
	        sparse::pos[i]=sparse::pos[i-1]+sparse::count[i-1];
	    }
	    for(int i=1 ;i<=s1.nz ;i++)
	    {
	        p =sparse::pos[s1.sp[i][1]];
	        sp[p][0]=s1.sp[i][1];
	        sp[p][1]=s1.sp[i][0];
	        sp[p][2]=s1.sp[i][2];
	        sparse::pos[s1.sp[i][1]]++;


	    }
	    nz=s1.nz;


	}


int main()
{
	sparse s1,s2,a,b,c;
	cout<<"\nThe first matrix:";
	s1.accept();
	s1.display();
	cout<<"\nThe second matrix:";
	s2.accept();
	s2.display();
	char ch;
	int n;
	do
	{
		cout<<"\n1)Addition\t2)Transpose\t3)Fast Transpose";
		cout<<"\nEnter your choice:";
		cin>>n;
		switch(n)
		{
		case 1:

			cout<<"\n**ADDITION OF SPARSE MATRIX**";
			a.addsp(s1,s2);
			a.display();
			break;
		case 2:

			cout<<"\n**TRANSPOSE OF SPARSE MATRIX**";
			b.transpose(s1);
			b.display();
			break;
		case 3:

			cout<<"\n**FAST TRANSPOSE OF SPARSE MATRIX**";
			c.fast_transpose(s1);
			c.display();
			break;
		default:
			cout<<"\nInvalid choice";
			break;
		}
		cout<<"\nDo you want to continue?(y/n)";
		cin>>ch;
	} while(ch=='y' || ch=='Y' );

	return 0;

}



/*  OUTPUT:
 The first matrix:
Enter the number of rows: 4

Enter the number of columns: 4

Enter the number of non zero values: 3

Enter the row number of non zero value:1

Enter the column number of non zero value:2

Enter the non zero value:3

Enter the row number of non zero value:2

Enter the column number of non zero value:1

Enter the non zero value:5

Enter the row number of non zero value:2

Enter the column number of non zero value:3

Enter the non zero value:7

**SPARSE MATRIX**

		4		4		3
		1		2		3
		2		1		5
		2		3		7

The second matrix:
Enter the number of rows: 4

Enter the number of columns: 4

Enter the number of non zero values: 2

Enter the row number of non zero value:1

Enter the column number of non zero value:3

Enter the non zero value:8

Enter the row number of non zero value:2

Enter the column number of non zero value:4

Enter the non zero value:9

**SPARSE MATRIX**

		4		4		2
		1		3		8
		2		4		9

1)Addition	2)Transpose	3)Fast Transpose
Enter your choice:1

**ADDITION OF SPARSE MATRIX**
**SPARSE MATRIX**

		4		4		5
		1		2		3
		1		3		8
		2		1		5
		2		3		7
		2		1		5

Do you want to continue?(y/n)y

1)Addition	2)Transpose	3)Fast Transpose
Enter your choice:2

**TRANSPOSE OF SPARSE MATRIX**
**SPARSE MATRIX**

		4		4		3
		1		2		5
		2		1		3
		3		2		7

Do you want to continue?(y/n)y

1)Addition	2)Transpose	3)Fast Transpose
Enter your choice:3

**FAST TRANSPOSE OF SPARSE MATRIX**
Fast Transpose is =
**SPARSE MATRIX**

		4		4		3
		1		2		5
		2		1		3
		3		2		7

Do you want to continue?(y/n)n

 */
