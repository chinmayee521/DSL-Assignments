/*quick sortPROGRAM
Name:Pranali Shinde
Roll No:SECOB245
Batch:B3
Division:B
*/
#include<iostream>
using namespace std;
class sort
{
    //float m[50];
    int i,n,j;
    public:
    float m[50];
        void accept()
        {
            cout<<"enter total students\n";
            cin>>n;
            cout<<"enter marks of student\n";
            for(i=0;i<n;i++)
            {
                cin>>m[i];
            }
        }
        float getm()
        {
            return m[50];
        }
        int getn()
        {
            return n-1;
        }
        void display()
        {
            cout<<"Marks are as follows\n";
            for(i=0;i<n;i++)
            {
            cout<<m[i]<<"  ";
            }
            cout<<endl;
        }
                void top5()
        {
            float a;
            for(i=n-1;i>=n-5;i--)
            {
                cout<<m[i]<<"  ";
            }
            cout<<endl;
        }
        void quick(float a[],int l,int h)
        {
            int j;
            if(l<h)
            {
                j=partition(a,l,h);
                quick(a,l,j-1);
                quick(a,j+1,h);
            }
        }
        int partition(float a[],int l,int h)
        {
            int pivot,pindex,j,temp;
            pivot=a[l];
            pindex=l;
            j=h+1;
            do
            {
                do
                {
                	pindex++;
                }while(a[pindex]<=pivot&&pindex<=h);
                do
                {
                    j--;
                }while(pivot<a[j]);
                if(pindex<j)
                {
                    temp=a[pindex];
                    a[pindex]=a[j];
                    a[j]=temp;
                }
            }while(pindex<j);
            a[l]=a[j];
            a[j]=pivot;
            return j;
        }
};
int main()
{
    sort s1,s2,s3,s4;
    s1.accept();
    s1.display();
    int ch,in,a,temp;
    do
    {
        cout<<"Enter\n1.quick sort\n2.top 5 students roll no\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            s1.quick(s1.m,0,s1.getn());
            s1.display();
            break;
            case 2:
            s1.top5();
            break;
        }
        cout<<"continue?\nPress 1 to continue\n";
        cin>>in;
    }while(in==1);

    return 0;
}
/*
OUTPUT:
enter total students
6
enter marks of student
55 88 33 22 12 09
Marks are as follows
55  88  33  22  12  9
Enter
1.quick sort
2.top 5 students roll no
1
Marks are as follows
9  12  22  33  55  88
continue?
Press 1 to continue
1
Enter
1.quick sort
2.top 5 students roll no
2
88  55  33  22  12
continue?
Press 1 to continue
0
*/




