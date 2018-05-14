#include<iostream>

using namespace std;

class fib
{
int n,c,d,x;
int f1,f2,f3;
int C[100];
public:
void input1();
int algo1(int n);
void input2();
int algo(int num);
};

void fib::input1()
{
cout<<"\nEnter the number of terms in the series:";
cin>>n;
for(int i=0;i<100;i++)
C[i]=-1;
c=0;
x=algo1(n);
cout<<"\nThe nth fibonacci number with dynamic programming is "<<x;
cout<<"\nNumber of counts: "<<c;
}

int fib::algo1(int n)
{c++;
if(C[n]!=-1)
return C[n];
if(n==1)
return 0;
if(n==2)
return 1;
else
{
C[n]=algo1(n-1)+algo1(n-2);
}
return C[n];
}


/*f1=0;
f2=1;
if(n==1)
cout<<"\nThe nth fibonacci number is "<<f1<<"\nNumber of counts: "<<c;
if(n==2)
cout<<"\nThe nth fibonacci number is "<<f2<<"\nNumber of counts: "<<c;
if(n>2)
{
for(int i=3;i<=n;i++)
	{c++;
	 f3=f1+f2;
	 f1=f2;
	 f2=f3;}
cout<<"\nThe nth fibonacci number is "<<f3<<"\nNumber of counts: "<<c;
}*/


void fib::input2()
{
d=0;
cout<<"\nEnter the number of terms in the series:";
cin>>n;
x=algo(n);
cout<<"\nThe nth fibonacci number is "<<x;
cout<<"\nThe count without dynamic programming is "<<d;
}

int fib::algo(int num)
{d++;
if(num==1)
return 0;
else if(num==2)
return 1;
else
{
return (algo(num-1)+algo(num-2));
}
}

int main()
{fib f;
f.input1();
f.input2();
return 0;
}
