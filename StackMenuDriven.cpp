 /* Stack using Array (Menu driven) */

#include<iostream>

using namespace std;

class Stack{
	public:
		int id;
		char username[20];
		
	void push()
	{
		cout<<"\n Enter Id:";
		cin>>id;
		
		cout<<"\n Enter Username :";
		cin>>username;
	}
	
	void iterate()
	{
		cout<<"\n "<<id<<"\t"<<username;
	}
};

Stack *container = NULL;
int top=-1;

void createStack(int n)
{
	container = new Stack[n];
	
	
	while(top<n-1)
	{
		top++;
		container[top].push();
		
	}
}

void showStack(int n)
{
	if(top==-1)
	{
		cout<<"\n Stack is Empty";
	}
	else
	{
		int i=top;
		while(i!=-1)
		{
			container[i].iterate();
			i--;
		}
	}
}

void pop()
{
	if(top==-1)
	{
		cout<<"\n Stack is Empty";	
	}	
	else
	{
		top--;
		cout<<"\n Stack Object Popped";
	}
}

int main()
{
	int stackSize ;
	int choice;

	
	while(1)
	{
		cout<<"\n 1.push the Object ";
		cout<<"\n 2.show all objects.";
		cout<<"\n 3.pop the object.";

		cout<<"\n Enter choice :";
	    cin>>choice;

		switch(choice)
	{
	    case 1:
		       cout<<"\n Enter no. of object to push :";
			   cin>>stackSize;
				createStack(stackSize);
				cout<<"\n Object Pushed in Stack";
				break;

	    case 2:
		        showStack(stackSize);
				
				break;
		       
		case 3:
				 pop();
				 
				break;
		default :
		       cout<<"\n Invalid choice !!";
		
	}
	}
	return 0;
}
