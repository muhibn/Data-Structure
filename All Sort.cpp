#include <iostream>
#include <conio.h>
using namespace std;
template <class t>
class Sort 
{
	int size;
	public:
		Sort(int);
		void getdata(t *);
		void bubble(t *);
		void insertionSort(t *);
		void mergeSort(t *,int,int);
		void merge(t *, int, int,int);
		void quickSort(t *,int,int);
		int partation(t *,int,int); 
		void selectionSort(t *,int);
		void countSort(t *,int,int);
		//ridax Sort all function
		int maxElem(t *,int);
		void ridaxSort(t *,int); 
		void counting(t*,int,int);
		//complete 
		void backutSort(t *,int);
		//Heap Sort 
		void heapify(t*,int,int);
		void heapSort(t*,int);
		
		void display(t *);
		
};
template <class t>
Sort<t>::Sort(int n)
{
     size=n;
	
}
template <class t>
void Sort<t>::display(t arr[])
{
	cout<<endl;
	
	for (int i=0;i<size;i++)
	  cout<<"____";
	cout<<endl;
	for (int i=0;i<size;i++)
	{
		cout<<" | "<<arr[i];
	}
	cout<<endl;
	for (int i=0;i<size;i++)
	cout<<"----";
}
template <class t>
void Sort<t>::bubble(t arr[])
{

	cout<<" Bubble Sort \n ";
	for(int i=0;i<size-i+2;i++)
	{
		for(int j=0;j<size-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				
			   t temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				
			}
		}
	}
	display(arr);
}
template <class t>
void Sort<t>::insertionSort(t arr[])
{
	t key;
	int j=0;
	for(int i=1;i<size; i++)
	{
		key=arr[i];
		j=i-1;
		
		while(arr[j]>key && j>=0){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
	display(arr);
}
template <class t>
void Sort<t>::mergeSort(t arr[],int p,int r)
{
	if(p<r)
	{
		int q=(r+p)/2;
		mergeSort(arr,p,q);
		mergeSort(arr,q+1,r);
	
		merge(arr,p,q,r);
			display(arr);
		
	}
	
	   
	
	
}
template<class t>
void Sort<t>:: merge(t arr[],int p,int  q,int r)
{
	int n1=q-p+1;
	
	int n2=r-q;
	
	t arr1[n1];
	t arr2[n2];
	
	int i=0,j=0,k=0;
	
	for(i=0;i<n1;i++)
	   arr1[i]=arr[i+p];
	   
	for(j=0;j<n2;j++)
	   arr2[j]=arr[j+q+1];   
	i=j=0;
	k=p;
	while(i<n1 && j<n2)
	{
		if(arr1[i]<=arr2[j])
		   arr[k++]=arr1[i++];
		else 
		    arr[k++]=arr2[j++];
	}
	while(i<n1)
	    arr[k++]=arr1[i++];
	while(j<n2)
	      arr[k++]=arr2[j++];
	
}
template <class t>
void Sort<t>::quickSort(t arr[],int p,int r)
{
	if(r>p)
	{
		int pvt=partation(arr,p,r);
		
		quickSort(arr,p,pvt-1);
		quickSort(arr,pvt+1,r);
		
	}
}
template<class t>
int  Sort<t>::partation(t arr[],int low,int r) 
{
	int pvt=arr[r];
	
	int i=low-1;
	
	for(int j=low;j<r;j++)
	{
		if(arr[j]<pvt)
		{
			i++;
			t temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
			}    
		    
	}
	i++;
     arr[r]=arr[i];
	arr[i]=pvt;
	
	return i;
}
template <class t>
void Sort<t>::selectionSort(t arr[],int n)
{
	int smallest=0;
	for(int i=0;i<n-1;i++)
	{
		smallest=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[smallest]>arr[j])
			   smallest=j;
		}
		int temp=arr[i];
		arr[i]=arr[smallest];
		arr[smallest]=temp;
	}
}
template<class t>
void Sort<t>::countSort(t arr[],int n,int range)
{
	
	t rangearr[range];
	for(int i=0;i<range;i++)
	        rangearr[i]=0;
	for(int i=0;i<n;i++)
	   rangearr[arr[i]]+=1;
	display(rangearr);
	int k=0,j=0;
	while(k<range)
	{
		int i=0;
		while(i<rangearr[k])
		{
			arr[j]=k;
			i++;
			j++;
		}
		k++;
	}
	   
}

template <class t>
int Sort<t>::maxElem(t arr[],int n)
{
	t max=0;
	for(int i=0;i<n;i++)
	     if(arr[i]>max)
	         max=arr[i];
	
	return max;
	
}
template <class t>
void Sort<t>::ridaxSort(t arr[],int n)
{
	t max=maxElem(arr, n);
	for(int div=1;max/div>0;div*=10)
	{
		counting(arr,n,div);
	}
	
}
template <class t>
void Sort<t>::counting(t arr[], int n,int div)
{
	t output[n];
	t count[10]={0};
	for(int i=0;i<n;i++)
	   count[(arr[i]/div)%10]++;
	   
	   
	for (int i=1;i<10;i++)
	  count[i]+=count[i-1];
	
	for(int i=n-1;i>=0;i--)
	{
		output[count[((arr[i]/div)%10)]-1]=arr[i];
		
		count[(arr[i]/div)%10]--;
	}
	for(int i=0;i<n;i++)
	   arr[i]=output[i];
}
template<class t>
void Sort<t>::backutSort(t arr[],int n)
{
	t arrb[n]={0};
	
	for(int i=0;i<n;i++){
	
	    (arrb[arr[i]])++;
	    
	}
	    
	int j=0;
	for(int J=0,i=0;i<n;i++)
	   for (;arrb[i]>0;arrb[i]--)
	      arr[j++]=i;
	
	
}
template<class t>
void Sort<t>::heapSort(t arr[],int n)
{
	
	for(int i=n/2-1;i>=0;i--)
	{
		heapify(arr,n,i);
	}
	for(int i=n/2-1;i>=0;i--)
	{
		heapify(arr,n,i); 
	}
	for(int i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}
template <class  t>
void Sort<t>::heapify(t arr[],int n,int i)
{
	int  largest=i;
	int  l=2*i+1;
	int  r=2*i+2;
	if(l<n && arr[l]>arr[largest])
	    largest=l;
	
	if(r<n && arr[r]>arr[largest])
	  largest=r;
	  
	if(largest !=i)
	{
		swap(arr[i],arr[largest]);
		
		heapify(arr,n,largest);
	}
	
	
}
int main()
{
	int  n,choose;
	cout<<"Enter the size of array : ";
	cin>>n;
	Sort<char> obj(n);
	char arr[n];
	cout<<"Enter the element of array : \n ";
	for(int i=0;i<n;i++)
	{
	  cout<<"arr ["<<i<<"] : ";
	  cin>>arr[i];
    }
	  obj.display(arr);
	
	do{
		
		cout<<"\n Enter the choose \n";
		cout<<"1 for Bubble sort \n";
		cout<<"2 for insertion sort \n";
		cout<<"3 for merge sort  \n";
		cout<<"4 for quick sort \n";
		cout<<"5 for selection sort \n";
		cout<<"6 for count sort \n";
		cout<<"7 for ridax sort \n";
		cout<<"8 for backut sort \n";
		cout<<"9 for heap Sort \n";
		cout<<"10 for display \n";
		cout<<"11 for clear cmd \n";
		cout<<"0 for exit \n";
		cin>>choose;
		cout<<(sizeof(arr)/sizeof(arr[0]));
		
   		 switch(choose)
	  	 {
			case 1 : obj.bubble(arr);
		  	  break;
			case 2 : obj.insertionSort(arr) ;
		  	  break;
			case 3 : obj.mergeSort(arr,0,n-1);
		  	  break; 
			case 4 : obj.quickSort(arr,0,n-1); 
		 	  break;
		 	case 5 :obj.selectionSort(arr,n);
			  break;
			case 6 :cout<<"\n Enter the range :"<<endl;
			        int range;
			        cin>>range;
			        obj.countSort(arr,n,range);
			  break;
			case 7 :obj.ridaxSort(arr, n);
			  break;
			case 8 :obj.backutSort(arr,n);
			  break;
			case  9:obj.heapSort(arr,n);
			  break;
			case 10: obj.display(arr) ;
		 	  break;
			case 11 :system("cls");
			  break;
			case 0 : continue ;
	    	  break;
	    	default : cout<<"Wrong choose  : ";
		 }
	
	}while(choose !=0);
	
	getch();
	return 0;
}
