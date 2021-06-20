//============================================================================
// Name        : stack.cpp
// Author      : a
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;
#define size 20
class Stack
{
	int s[size];
	int top;
public:
	Stack()
{
		top=-1;
}
	bool isStackempty();
	bool isStackfull();
	void push(char);
	char pop();



};
bool Stack::isStackempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
bool Stack::isStackfull()
{
	if(top==size-1)
		return 1;
	else
		return 0;
}
void Stack::push(char ch)
{
	if(isStackfull())
		cout<<"\n..Stack is full..";
	else
	{

		top++;
		s[top]=ch;

	}
}

char Stack::pop()
{
	char ch;
	if(isStackempty())
	{
		cout<<"\n..Stack is empty..";
		ch='$';
		return ch;
	}
	else
	{
		ch=s[top];
		top--;

		return ch;
	}
}
int main()
{
	int i=0;
	string str;
	Stack S;

	cout<<"\nEnter the expression: ";
	cin>>str;
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]!='(' && str[i]!=')' && str[i]!='{' && str[i]!='}' && str[i]!='[' && str[i]!=']')
			{
			cout<<"\n..Not a valid expression..Enter again";
			cin>>str;
			}

	}
	cout<<"\nExpression is:"<<str;
			while(str[i]!='\0')
			{
				if(str[i]=='(' || str[i]=='{' || str[i]=='[')
				{
					S.push(str[i]);
				}
				if(str[i]==')' || str[i]=='}' || str[i]==']')
				{
					if(S.isStackempty())
					{
						cout<<"\nNot a valid expression";
						return 0;
					}
					else
					{
						char token=S.pop();
						if((str[i]==')' && token=='(') || (str[i]=='}' && token=='{') || (str[i]==']' && token=='[' ) )
						;
							else
							{
							cout<<"\nNot a valid expression";
							return 0;
							}


					}
				}
				i++;
			}
			if(S.isStackempty())
			{
				cout<<"\n..Valid expression..";
			}
			else
				cout<<"\n..Not a valid expression..";




	return 0;
}
