#include<iostream>
#include<cmath>

using namespace std;

double fact(double n)
{if(n==1||!n)
return 1;
else
return(fact(n-1)*n);
}

int main()
{
double n;
double T[7];
T[0]=1;
T[1]=T[0]*60;
T[2]=T[1]*60;
T[3]=T[2]*24;
T[4]=T[3]*30;
T[5]=T[4]*12;
T[6]=T[5]*100;

cout<<"\t1second\t1minute\t1hour \t1day  \t1month \t1year \t1century\n";
cout<<"n!:\t";
for(int i=0;i<7;i++)
{n=1;
while(int x=fact(n)<=T[i])
n++;
cout<<n<<"\t";
}
cout<<endl;

cout<<"2^n:\t";
for(int i=0;i<7;i++)
{n=1;
while(pow(2.0,n)<=T[i])
n++;
cout<<n<<"\t";
}
cout<<endl;

cout<<"n^3:\t";
for(int i=0;i<7;i++)
{n=1;
while(pow(n,3)<=T[i])
n++;
cout<<n<<"\t";
}
cout<<endl;

cout<<"n^2:\t";
for(int i=0;i<7;i++)
{n=1;
while(pow(n,2)<=T[i])
n++;
cout<<n<<"\t";
}
cout<<endl;

cout<<"nlogn:\t";
for(int i=0;i<7;i++)
{n=1;
while((n*log(n)/log(2))<=T[i] && n< 1.0e8)
n++;
cout<<n<<"\t";
}
cout<<endl;

cout<<"n:\t";
for(int i=0;i<7;i++)
{n=1;
while(n<=T[i] && n< 1.0e7)
n++;
cout<<n<<"\t";
}
cout<<endl;

cout<<"logn:\t";
cout<<"2"<<"\t";
for(int i=1;i<7;i++)
{n=2;
while(log(n)/log(2)<=T[i] && n< 1.0e7)
n++;
cout<<n<<"\t";
}
cout<<endl;

return(0);
}
