#include <iostream>
#include <conio.h>
using namespace std;
template <class t>
struct Nodeq{
	t data;
	Nodeq<t> *next;
	
};
template <class t>
class QueueList{
	private:
		Nodeq<t> *front,*rear;
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
	Nodeq<t> *n=new Nodeq<t>;
	n->data=value;
	n->next=NULL;
	if(empty())
	{
		front=rear=n;
		size++;
	}else{
		Nodeq<t> *temp=new Nodeq<t>;
		rear->next=n;
		rear=n;
		n->next=front;
		size++;
		
	}
}
template <class t>
t QueueList<t>::dequeue()
{
	Nodeq<t> *n=new Nodeq<t>;
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
	Nodeq<t> *temp=new Nodeq<t>;
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
	

