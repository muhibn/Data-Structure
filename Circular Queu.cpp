#include<iostream>
#include <conio.h>
#include<string>
using namespace std;
class RuntimeException
{
	private:
		string errorMsg;
		public :
		RuntimeException(const string& err){errorMsg = err;}
		string getmsg() const {return errorMsg;}
};
class QueueFull :public RuntimeException 
{
	public:
	QueueFull(const string& err):RuntimeException(err){}
	
};
class QueueEmpty :public RuntimeException
{
	public:
	QueueEmpty(const string& err):RuntimeException(err){};
	
};
template <class t>
class Queue
{
	private:
		int  N,front,top,rear;
		t *cq;
	public:
		Queue();
		Queue(int);
		bool isFull() const ;
		bool isEmpty() const ;
		void enqueue(const t&) throw (QueueFull);
		t dequeue()throw (QueueEmpty);
		void display();
		
};
template<class t>
Queue<t>::Queue(int n)
{
	N=n;
	cq=new t[N];
	rear=front=-1;
	for(int i=0;i<N;i++)
	  cq[i]=0;
}
template <class t>
bool Queue<t>::isEmpty() const
{
	if(rear==-1)
	{
		return true ;
	}
	else 
	{
		return false;
	}
}
template <class t>
bool Queue<t>::isFull() const 
{
	if ((rear+1)%N==front)
	{
		return true ;
	}
	else 
	{
		return false ;
	}
}
template <class t>
void  Queue<t>::enqueue(const t& value) throw (QueueFull)
{
	if(isFull())
	{
		throw QueueFull("Overflow");
	}
	else if(rear==-1)
	{
		rear=0;
		front=0;
		cq[rear]=value;
	}
	else 
	{
		rear=(rear+1)%N;
		cq[rear]=value;
	}
}
template <class t>
t Queue<t>::dequeue() throw (QueueEmpty)
{
	t devalue;
	if(isEmpty())
	{
		throw QueueEmpty("Underflow");
	}
	else if(rear==front)
	{
		devalue=cq[rear];
		rear=front=0;
		return devalue;
	}
	else{
		devalue=cq[front];
		cq[front]=0;
		front=(front+1)%N;
		
		return devalue;
	}
}
template <class t>
void Queue<t>::display()
{
	if(isEmpty())
	{
		throw QueueEmpty("Underflow");
	}
	int i=front;
	while(i!=rear)
	{
		cout<<"| "<<cq[i]<<" |";
		i=(i+1)%N;
	}
}
int main()
{
	int choose,n;
	cout<<"Enter the size of Queue ";
	cin>>n;
	Queue<int> obj(n);
	do{
		cout<<"Enter the Choose \n";
		cout<<"1 for enqueue value \n";
		cout<<"2 for dequeue value \n";
		cout<<"3 for isFull \n";
		cout<<"4 for isEmpty \n";
		cout<<"5 for display \n";
		cout<<"6 for clear cmd \n ";
		cout<<"0 for exit \n";
		
		cin>>choose;
		switch(choose)
		{
			case 1: int value;
					cout<<"Enter the value : ";
					cin>>value;
					obj.enqueue(value);
			  break;
			case 2 :cout<<"The value Dequeue : "<<obj.dequeue();
			  break;
			case 3 :cout<<"Queue is full : "<<obj.isFull();
			  break;
			case 4 :cout<<"Queue is Empty : "<<obj.isEmpty();
			  break;
			case 5 :obj.display();
			  break;
			case 6 :system("cls");
			  break;
			case 0 : continue;
			  break;
			default:cout<<"Wrong choose : ";
		}
		cout<<endl;
	}while(choose!=0);
	
	
	
	getch();
	return 0;
}

