#include <iostream>

using namespace std;
class Count
{
int p,q,sum,i,j,range,n,k;
int a[20],B[20],c[20],f[20],C[20];
public:
void read();
void countsort();
void output();
void Range();
};

void Count::read()
{
cout<<"\nEnter the size of the array:";
cin>>n;
cout<<"\nEnter the range of elements:";
cin>>k;
cout<<"\nEnter the elements of the array: ";
for(i=0;i<n;i++)
cin>>a[i];
}

void Count::countsort()
{
sum=0;
for(i=0;i<k;i++)
f[i]=0;
for(i=0;i<n;i++)
f[a[i]]++;
for(i=0;i<k;i++)
{
	sum=sum+f[i];
	c[i]=sum;
}
cout<<"\nCummulative frequency: ";
for(i=0;i<k;i++)
cout<<" "<<c[i];
for(i=0;i<k;i++)
C[i]=c[i];
for(i=n-1;i>=0;i--)
	{
	 c[a[i]]--;
	 B[c[a[i]]]=a[i];
	}

}

void Count::output()
{
cout<<"\nOutput:";
for(i=0;i<n;i++)
cout<<" "<<B[i];
}

void Count::Range()
{
cout<<"\nEnter the range to check- a and b :";
cin>>p>>q;
range=C[q]-C[p-1];
cout<<"\nNumber of integers in the range: "<<range;
}

int main()
{
Count obj;
obj.read();
obj.countsort();
obj.output();
obj.Range();
return(0);
}






