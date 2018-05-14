#include<iostream>

using namespace std;

class Arr
{
public:
int A[15];
int B[15];
int n;
int m;
void read();
void Union();
void Inter();
void Sum();
};

void Arr::read()
{cout<<"\nEnter the size of array A:";
cin>>n;
cout<<"\nEnter the size of array B:";
cin>>m;
cout<<"\nEnter the elements of array A in ascending order:";
for(int i=0;i<n;i++)
cin>>A[i];
cout<<"\nEnter the elements of array B in ascending order:";
for(int j=0;j<m;j++)
cin>>B[j];
}

void Arr::Union()
{
 int i=0;
 int j=0;
 cout<<"\nUnion of A and B:"<<" ";
while(i<n && j<m)
{
	if(A[i]<B[j])
	{
		cout<<A[i]<<" ";
		i++;
	}
	else if(A[i]>B[j])
	{
		cout<<B[j]<<" ";
		j++;
	}
	else
	{
		cout<<A[i]<<" ";
		i++;
		j++;
	}
}

while(i<n)
{
 cout<<A[i]<<" ";
 i++;
}

while(j<m)
{
 cout<<B[j]<<" ";
 j++;
}
}

void Arr::Inter()
{
int flag=0;
int i=0;
int j=0;
cout<<"\nIntersection of A and B is:"<<" ";
while(i<n && j<m)
{
	if(A[i]<B[j])
	{
		//cout<<A[i]<<" ";
		i++;
	}
	else if(A[i]>B[j])
	{
		//cout<<B[j]<<" ";
		j++;
	}
	else
	{
		cout<<A[i]<<" ";
		i++;
		j++;
		flag++;
	}
}
if(flag==0)
cout<<" NULL";
}

void Arr::Sum()
{
int flag=0;
int i=0;
int j=m-1;
int x;
int sum=0;
cout<<"\nEnter the value of X to be checked:";
cin>>x;
while(i<n && j>=0)
{
sum=A[i]+B[j];
if(sum>x)
j--;
else if(sum<x)
i++;
else if(sum==x)
	{
	 cout<<"\nValue of a and b is: "<<A[i]<<" and "<<B[j];
	 flag++;
	 break;
	 }
}
if(flag==0)
cout<<"\nNo a and b found of sum X!";
}

int main()
{
Arr X;
X.read();
X.Union();
X.Inter();
X.Sum();
return(0);
}
