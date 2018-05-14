#include<iostream>
using namespace std;

class BF
{
int A[10];
int n;
public:
void read();
void brute();
};

void BF::read()
{
cout<<"\nEnter the number of elements:";
cin>>n;
cout<<"\nEnter the values:";
for(int i=0;i<n;i++)
cin>>A[i];
}

void BF::brute()
{int msum=0;
for(int i=0;i<n;i++)
	{for(int j=i;j<n;j++)
		{int csum=0;
		    for(int k=i;k<=j;k++)
			csum=csum+A[k];
			if(msum<=csum)
			msum=csum;
		}
	}
cout<<"\nThe max sum is:"<<msum;
}


int main()
{
BF b;
b.read();
b.brute();
return(0);
}

