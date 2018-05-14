#include<stdio.h>
#include<iostream>
#include<cmath>

using namespace std;

class SSS
{
public:
int n;
int x;
int sum;
int a[10],b[10];
void read();
void algo();
};

void SSS::read()
{
cout<<"\nEnter the number of elements in set:";
cin>>n;
for(int i=0;i<n;i++)
{a[i]=0;
 cout<<"\nEnter the value of element "<<i+1<<" :";
 cin>>b[i];
}
cout<<"\nEnter the subset sum to be checked for:";
cin>>x;
}

void SSS::algo()
{
for(int c=1;c<=(int)pow(2,n);c++)
{sum=0;
 for(int i=0;i<n;i++)
 { 
  if(c%(int)pow(2,i)==0)
  {if(a[i]==0)
   a[i]=1;
   else if(a[i]==1)
   a[i]=0;}
 }
for(int j=0;j<n;j++)
sum+=a[j]*b[j];
if(sum==x)
{cout<<"\nSubset is: ";
 for(int i=0;i<n;i++)
 if(a[i]==1)
 cout<<b[i]<<" ";
 return;}
}
cout<<"\nNot found!";
}

int main()
{
SSS sub;
sub.read();
sub.algo();
return 0;
}

