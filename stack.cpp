#include<iostream>
#include <conio.h>
#include<string>
using namespace std;
class RuntimeException
{
	private:
		string errorMsg;
	public:
		RuntimeException(const string& err)
		{
			errorMsg=err;
		}
		string getmsg() const
	   {
	   		return errorMsg;
		}

};
class StackEmpty : public RuntimeException
{
	public:
	StackEmpty (const string& err):RuntimeException(err){}
};
class StackFull : public RuntimeException
{
	public:
		StackFull(const string& err):RuntimeException(err){}
		
}; 
template<class t>
class Stack
{
	int N;
	t *arr;
	int top;
	public :
		Stack();
		Stack(int n);
		bool isEmpty() const ;
		bool isFull() const ;
		void push(const t&) throw (StackFull);
		t    pop() throw (StackEmpty);
		void display();
		
};
template<class t>
Stack<t>::Stack(int n)
{
	N=n;
	arr=new t[N];
	for(int i=0;i<N;i++)
	  arr[i]=0;
	  
	top=-1;
}
template <class t>
bool Stack<t>::isEmpty() const
{
	if(top==-1)
	{
		return true;
	}
	else
	{
		return false ;
	}
	
}
template <class t>
bool Stack<t>::isFull() const 
{
	if(top==N-1)
	{
		return true ;
	}
	else 
	{
		return false ;
	}
}
template<class t>
void Stack<t>::push(const t& value) throw (StackFull)
{
	if(isFull())
	{
		throw StackFull("overflow");
	}
	else{
		top++;
		arr[top]=value;
	}

}
template <class t>
t Stack<t>::pop() throw (StackEmpty)
{
	int popvalue;
	if(isEmpty())
	{
		throw StackEmpty("Underflow");
	}
	else 
	{
		popvalue=arr[top];
		arr[top]=0;
		top--;
		return popvalue;
	}
	
	
}
template <class t>
void Stack<t>::display()
{
	int travel=N-1;
	if(isEmpty())
	{
		throw StackEmpty("Underflow");
	}
	else
	{
		cout<<"data of Stack = "<<endl;
		while(travel>=0)
		{ 
			cout<<"|   "<<arr[travel]<<"    |"<<endl;
			cout<<"|--------|"<<endl;
		
		travel--;
		}
		
	}
}
int main()
{
	int n ;
	cout<<"Enter the size of Stack : ";
	cin>>n;
	Stack<int> obj(n);
	int choose;
	
	do
	{
		cout<<"Enter the choose : \n";
		cout<<"1 for push the value  \n";
		cout<<"2 for pop the value \n";
		cout<<"3 for is empty \n";
		cout<<"4 for is full \n";
		cout<<"5 display the stack \n";
		cout<<"6 for clear the cmd \n";
		cout<<"0 for exit \n ";
		cin>>choose;
		switch(choose)
		{
			case 1 :int value ;
			        cout<<"Enter the value : ";
			        cin>>value;
			        obj.push(value);
			  break;
			case 2 : cout<<"The pop it  value : "<<obj.pop()<<endl;;
			  break;
			case 3 :cout<<obj.isEmpty();
			  break;
			case 4 :cout<<obj.isFull();
			  break;
			case 5 :obj.display();
			  break;
			case 6 : system("cls");
			  break;
			case 0 : continue;
			  break;
			default :cout<<"Wrong choose \n ";
			
		}
		
	}while(choose!=0);
	
	getch();
	
	
	return 0; 
}

