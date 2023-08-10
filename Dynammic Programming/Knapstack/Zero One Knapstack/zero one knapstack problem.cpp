#include <iostream>
#include <conio.h>
using namespace std;
class Knapstack
{
	public:
		int  functKnapstack(int*,int*,int,int);
		void iterativeKnapstack(int*,int*,int,int);
};
int Knapstack::functKnapstack(int *wr, int *vr,int w, int n)
{
	if(n==0||w==0)
	  return 0;
	
	if(wr[n-1]<=w)
	{
		return max(vr[n-1]+functKnapstack(wr,vr,w-wr[n-1],n-1),functKnapstack(wr,vr,w,n-1));
	}else{
		return functKnapstack(wr,vr,w,n-1);
	}
}
void Knapstack::iterativeKnapstack(int *wr,int *vr,int w,int n)
{
	int k[n][w];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(i==0||j==0)
			{
				k[i][j]=0;
			}else if (wr[i-1]<=w){
				k[i][j]=max(vr[i-1]+k[i-1][j-wr[i-1]],k[i-1][j]);
			}else{
				k[i][j]=k[i-1][j];
			}
		}
	}
	
	cout<<" cout the maximum profit is : "<<k[n-1][w-1];
}
int main()
{
	int w,n;
	cout<<"Enter the number of item : ";
	cin>>n;
	cout<<"Enter the size of knapstack : ";
	cin>>w;
	 int wr[n],vr[n];
	//int wr[n]={10,10,30,40};
	//int vr[n]={40,40,100,120};
	
	cout<<"Enter the weight and value of item : "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Weight of item "<<i+1<<" :";
		cin>>wr[i];
		cout<<"value of item "<<i+1<<" :";
		cin>>vr[i];
	}

	
	//create object of class knapstack 
	Knapstack obj; 
	
	int choose;
	do{
		cout<<"Enter your choose\n";
		cout<<"1 for recursive \n";
		cout<<"2 for iterative \n ";
		cin>>choose;
		
		switch(choose){
			
			case 1 :cout<<"finall answer : "<<obj.functKnapstack(wr,vr,w,n);
			  break;
			case 2 :obj.iterativeKnapstack(wr,vr,w,n);
			  break;
			default :cout<<"wrong choose ";
		}
		cout<<endl;
	}while(choose!=0);
	
	
	
	

	
	
	getch();
	return 0;
}

