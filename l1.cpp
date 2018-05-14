#include<iostream>
#include<cmath>

using namespace std;

int main()
{
int n=2;
float i,j,k;
i=8*n*n;
j=log(n)/log(2);
k=64*n*j;
cout<<endl<<"Values of n for which insertion sort beats merge sort:";
//cout<<"\n"<<n;

for(int x=3;i<=k;x++)
	{if(i>k)
	return(0);
	cout<<"\n"<<n;
	n=x;
	i=8*n*n;
	j=log2(n);
	k=64*n*j;
	
	}
return(0);	
}

