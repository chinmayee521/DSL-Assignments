#include<iostream>
using namespace std;
#define size 10
class Sort
{
public:
	float a[size];
	void accept();
	void bubble();
	void selection();
	void display();
};

void Sort :: accept()
	{
		cout<<"\n Enter marks of students to be sorted:";
		for(int i=0;i<size;i++)
		{
			cin>>a[i];
		}
	}

	void Sort:: bubble()
	{
		cout<<"\n Using bubble sort:";
		for(int pass=1;pass<size;pass++)
		{
			for(int i=0;i<size-pass;i++)
			{
				if(a[i]>a[i+1])
				{
					float temp=a[i];
					a[i]=a[i+1];
					a[i+1]=temp;
				}
			}
		}
	}

	void Sort:: selection()
	{
		cout<<"\n Using selection sort:";
		int min;
		for(int i=0;i<size;i++)
		{
			min=i;
			for(int j=i+1;j<size;j++)
			{
				if(a[min]>a[j])
				{
					min=j;
				}
				float temp=a[i];
				a[i]=a[min];
				a[min]=temp;
			}
		}
	}

	void Sort :: display()
	{
		cout<<"\n Sorted marks list is:";
		for(int i=size-1;i>=size-5;i--)
		{
			cout<<"\n"<<a[i];
		}
	}

int main()
{
	Sort s;
	int ch;
	while(-1)
	{
		cout<<"\n Enter choice:\n 1.Enter data \n 2.Bubble sort \n 3.Selection sort\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
			s.accept();
			break;
		case 2:

				s.bubble();
				s.display();
				break;
		case 3:
				s.selection();
				s.display();
				break;
		}
	}

	return 0;
}
