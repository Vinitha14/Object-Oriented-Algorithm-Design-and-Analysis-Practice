#include<iostream>
#include<algorithm>

using namespace std;

int M,N;

class knapsack
{
public:
float fraction;
int p;
int s;
void input();
void algo();
void disp();
void sort();
}k[20];

void knapsack::input()
{
for(int i=0;i<N;i++)
	{cout<<"\nEnter the size(in bits) of the job "<<i+1<<":";
   	 cin>>k[i].s;
	 cout<<"\nEnter the profit of the job "<<i+1<<":";
	 cin>>k[i].p;
	 k[i].fraction=(float)k[i].p/k[i].s;}
}

void knapsack::disp()
{
cout<<"\nSize"<<"\t"<<"Profit"<<"\t"<<"Fraction";
for(int i=0;i<N;i++)
cout<<"\n"<<k[i].s<<"\t"<<k[i].p<<"\t"<<k[i].fraction;
}

void knapsack::sort()
{
for(int i=0;i<N;i++)
	for(int j=0;j<N-i-1;j++)
{
if(k[j].fraction<=k[j+1].fraction)
{
knapsack temp;
temp=k[j];
k[j]=k[j+1];
k[j+1]=temp;
}
}
}

void knapsack::algo()
{
float solution=0;
float frac=0;
int i=0;
while(M>0)
{
if(M>=k[i].s)
{solution+=k[i].p;
M-=k[i].s;
}
else
{frac=(float)M/k[i].s;
solution=solution+frac*k[i].p;
M=0;
}
i++;
}
cout<<"\nMaximum profit is:"<<solution;
}

int main()
{
cout<<"\nEnter the size of the main memory:";
cin>>M;
cout<<"\nEnter the number of jobs:";
cin>>N;
k[0].input();
cout<<"\nBefore sorting:";
k[0].disp();
k[0].sort();
cout<<"\nAfter sorting:";
k[0].disp();
k[0].algo();
return 0;
}
