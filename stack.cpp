#include<bits/stdc++.h>
using namespace std;
int a[50],size,top=-1;
void push()
{
    int item;
    if(top == size -1) cout<<"\nStack OVERFLOW\n.";
    else
    {
        cout<<"\nEnter push item :";
        cin>>item;
        top++;
        a[top] = item;
    }
}
void pop()
{

    if(top == -1) cout<<"\nStack UNDERFLOW.\n";
    else
    {
    	cout<<"\nRemove item :" <<a[top] ;
        top = top-1;
    }
}

void show()
{
    int index;
    if(top == -1) cout<<"\nStack UNDERFLOW\n";
    else
    {
        cout<<"\nValues of stack are :" << " ";
        index = top;
        while(index >= 0)
        {
            cout<<" "<<a[index];
            index--;
        }

    }
}
void top_item()
{

   if(top == -1) cout<<"Invalid item\n";
   else cout<<"Top value from the stack is :"<<a[top];
}

int main()
{
	cout<<"Enter the size of stack :";
	cin>>size;
	while(1)
	{
		int option;
		cout<<"\n1.PUSH.\n2.REMOVE.\n3.SHOW.\n4.TOP ITEM.\n5.EXIT.\n";
		cout<<"Enter your choice :";
		cin>>option;
		switch(option)
		{
			case 1:push();
			       break;
			case 2:pop();
			       break;
			case 3:show();
			       break;
			case 4:top_item();
			       break;
			case 5:exit(0);
			default:
				printf("Wrong choice\n");

				return 0;
		}
	}
}