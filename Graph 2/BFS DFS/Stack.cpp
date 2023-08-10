#include <iostream>
#include <conio.h>
using namespace std;
template <class t>
struct Node{
	t data;
	Node<t> *next;
	
};
template <class t>
class StackList
{
	private:
		Node<t> *tops;
	public:
		StackList();
	    bool empty();
	    t top();
	    void push(const t&);
	    t pop();
	    void display();
	
};
template <class t>
StackList<t>::StackList(){
	
	tops=NULL;
}
template <class t >
bool StackList<t>::empty()
{
	if(tops==NULL)
	  {
	  	return true ;
	  }else{
	  	 return false ;
	  }
}
template <class t>
void StackList<t>::push(const t& value)
{
	Node<t> *n=new Node<t>;
	n->data=value;
	n->next=tops;
	tops=n; 
}
template <class t>
t StackList<t>::pop()
{
	if(empty())
	{
		cout<<"Stack is underflew";
		return 0;
		
	}else 
	{
	Node<t> *n=new Node<t>;  
	n=tops;
	t data=n->data;
	tops=tops->next;
	delete n;
	return data;
   }
}
template <class t>
void StackList<t>::display()
{
	if(empty())
	{
		cout<<"cout the stack is empty";
	}else{
		Node<t> *n=new Node<t>;
		n=tops;
		while(n!=NULL)
		{
			cout<<"-->"<<n->data;
			n=n->next;
		}
	}
}
