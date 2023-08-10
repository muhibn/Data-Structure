#include <iostream>
#include <conio.h>
using namespace std;
template <class t>
struct Node{
	t data;
	Node<t> *next;
	
};
template <class t>
class QueueList{
	private:
		Node<t> *front,*rear;
		int size;
	
	public:
		QueueList();
		bool empty()const ;
		void enqueue(const t&);
		t   dequeue();
		void display()const;
		int sizes()const ;
		
};
template<class t>
QueueList<t>::QueueList()
{
	front=NULL;
	rear=NULL;
	size=0;
}
template <class t>
bool  QueueList<t>::empty()const
{
	if(size==0)
	{
		return true;
	}else{
		return false;
	}
}
template <class t>
int  QueueList<t>::sizes()const 
{
	return size;
}
template <class t>
void QueueList<t>::enqueue(const t& value)
{
	Node<t> *n=new Node<t>;
	n->data=value;
	n->next=NULL;
	if(empty())
	{
		front=rear=n;
		size++;
	}else{
		Node<t> *temp=new Node<t>;
		rear->next=n;
		rear=n;
		n->next=front;
		size++;
		
	}
}
template <class t>
t QueueList<t>::dequeue()
{
	Node<t> *n=new Node<t>;
	if(empty())
	{
		cout<<"Queue is empty";
		return 0;
	}else if(rear==front)
	{
		t value=front->data;
		 front=rear=NULL;
		 size=0;
		 return value;
	}
	else{
		
		size--;
		t value=front->data;
		n=front;
		front=front->next;
		rear->next=front;
		delete n;
		return value;
		
	}
}
template<class t>
void  QueueList<t>::display()const 
{
	Node<t> *temp=new Node<t>;
	if(empty())
	{
		cout<<"Queue is Empty ";
	}else{
		temp=front;
		do{
				
		
			cout<<"-->"<<temp->data;
			temp=temp->next;
		}		while(temp!=front);

	}
	
}
int main()
{
	QueueList<int> obj;
	int choose;
	do{
		cout<<"Enter the choose \n";
		cout<<"1 for enqueue \n";
		cout<<"2 for dequeue \n";
		cout<<"3 for is empty \n";
		cout<<"4 for size of queue \n";
		cout<<"5 for display \n ";
		cout<<"0 for exit \n ";
		cin>>choose;
		switch(choose)
		{
			case 1 :int value;
			        cout<<"Enter the for  enqueue : ";
			        cin>>value;
			        obj.enqueue(value);
			 break;
			case 2 :cout<<obj.dequeue();
			 break;
			case 3 : obj.empty();
			 break;
			case 4 : cout<<"Number of element exist : "<<obj.sizes();
			 break;
			case 5 : obj.display();
			 break;
			case 0 : continue;
			default:cout<<"Wrong choose ";
		}
		cout<<endl;
	}while(choose!=0);
}
