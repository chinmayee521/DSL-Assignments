//============================================================================
// Name        : infix_to_postfix.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class stack
{
	char infix[20];char postfix[20];
	int instk, incoming;
	int top;  //top for stk
//	int top1; //top for stk1
	char stk[10]; //exp conversion
	//int stk1[10]; //exp evaluation


public:
	stack()
	{

		top=-1;
		//top1=-1;
		instk=0;
		incoming=0;
	}

	void get_infixexp()
	{
		cout<<"\nEnter the infix expression: ";
		cin>>infix;
	}
	void show_infix()
	{
		cout<<"\n Infix expression: "<<infix;
	}
	bool isStackempty()
	{
		if(top==-1)
			return 1;
		else
			return 0;
	}
	bool isStackfull()
	{
		if(top==9)
		{
			return 1;
		}
		else
			return 0;
	}
	void ipush1(int x)  //int stk
	{
		top++;
		stk[top]=x;
	}
	int ipop1()   //int stk
	{
		int s1;
		s1=stk[top];
		top--;
		return s1;
	}
	void cpush(char y)  //char stk
	{
		top++;
		stk[top]=y;
	}
	char cpop()  //char stk
	{
		char s;
		s=stk[top];
		top--;
		return s;

	}
	void convert();
	int instackpriority();
	int incomingpriority(char);
	void show_postfix()
	{
		cout<<"\n"<<postfix;
	}
	void postfix_eval();


};

int stack::instackpriority()
{
	char a;
	a=stk[top];
	if(a=='(')
		return 0;
	else if (a=='+')
		return 1;
	else if(a=='-')
		return 1;
	else if(a=='*')
		return 2;
	else if(a=='/')
		return 2;
	else if(a=='^')
		return 3;
}

int stack::incomingpriority(char b)
{
	if(b=='(')
		return 0;
	else if(b=='+')
		return 1;
	else if(b=='-')
		return 1;
	else if(b=='*')
		return 2;
	else if(b=='/')
		return 2;
	else if(b=='^')
		return 4;

}
void stack::convert()
{
	int i=0,j=0;
	char p,q;
	while(infix[i]!='\0')
	{
		p=infix[i];

		if(p=='(' || p=='+' || p=='-' || p=='*' || p=='/' || p=='^' || p==')')
		{
			if(isStackempty())
			{
				cpush (p);
			}
			else if(p==')')
			{
				q=cpop();
				while(q!='(')
				{
					postfix[j]=q;
					j++;
					q=cpop();
				}

			}
			else if(p=='(')
			{
				cpush(p);
			}
			else
			{
				instk=instackpriority();
				incoming=incomingpriority(p);
				if(instk>=incoming)
				{
					q=cpop();
					postfix[j]=q;
					j++;
					cpush(p);
				}
				else
				{
					cpush(p);
				}
			}
		}//end of outer if
		else
		{
			postfix[j]=p;
			j++;
		}
		i++;
	}//end of while

	if(infix[i]=='\0')
	{
		while(!isStackempty())
		{
			q=cpop();
			postfix[j]=q;
			j++;
		}
	}
	postfix[j]='\0';
}

void stack::postfix_eval()
{
	int i=0;
	char ch;
	int op1,op2,ans,final;

	while(postfix[i]!='\0')
	{
		ch=postfix[i];

		if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
		{
			switch(ch)
			{
			case '+':
				op2=ipop1();
				op1=ipop1();
				ans=op1+op2;
				ipush1(ans);
				break;
			case '-':
				op2=ipop1();
				op1=ipop1();
				ans=op1-op2;
				ipush1(ans);
				break;
			case '*':
				op2=ipop1();
				op1=ipop1();
				ans=op1*op2;
				ipush1(ans);
				break;
			case '/':
				op2=ipop1();
				op1=ipop1();
				ans=op1/op2;
				ipush1(ans);
				break;
			case '^':
							op2=ipop1();
							op1=ipop1();
							ans=op1;
							while(op2>1)
							{
								ans=ans*op1;
								op2--;
							}
							ipush1(ans);
							break;
			}
		}
		else if(ch>='0' && ch<='9')
		{
			ipush1(ch-'0');
		}
		i++;

	}
	final=ipop1();
	cout<<"\nResult is= "<<final;
}
int main()
{
	stack s;
	s.get_infixexp();
	s.show_infix();
	cout<<"\n\nINFIX TO POSTFIX";
	s.convert();
	s.show_postfix();
	cout<<"\n\nPOSTFIX EXPRESSION EVALUATION:\n";
	s.postfix_eval();
	return 0;
}
