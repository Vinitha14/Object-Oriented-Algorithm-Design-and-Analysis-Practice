#include<stdio.h>
#include<iostream>
#include<cmath>

using namespace std;

class ks
{
public:
int n,x;
int tw,tp;
int sum;
int a[10],w[10],p[10];
void read();
void disp();
void algo();
};

void ks::read()
{
cout<<"\nEnter the number of elements:";
cin>>n;
for(int i=0;i<n;i++)
{a[i]=0;
 cout<<"\nEnter the weight of element "<<i+1<<" :";
 cin>>w[i];
 cout<<"\nEnter the price of element "<<i+1<<" :";
 cin>>p[i];
}
disp();
cout<<"\nEnter the maximum weight allowed:";
cin>>x;
}

void ks::disp()
{
cout<<"\nWeight Price\n";
for(int i=0;i<n;i++)
cout<<w[i]<<"\t"<<p[i]<<"\n";
}

void ks::algo()
{
int max=0;
for(int c=1;c<=(int)pow(2,n);c++)
{sum=0;
 tp=0;
 for(int i=0;i<n;i++)
 { 
  if(c%(int)pow(2,i)==0)
  {if(a[i]==0)
   a[i]=1;
   else if(a[i]==1)
   a[i]=0;}
 }
for(int j=0;j<n;j++)
{sum+=a[j]*w[j];
tp+=a[j]*p[j];
}
if(sum<=x && tp>=max)
max=tp;
}
cout<<"\nMaximum price is :"<<max;
}

int main()
{
ks sack;
sack.read();
sack.algo();
return 0;
}

