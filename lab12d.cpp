#include<iostream>

using namespace std;

class ncr
{
int n,r,c,x;
int C[20][20];
public:
void input();
int algo(int n,int r);
};

void ncr::input()
{
cout<<"\nEnter the values of n and r:";
cin>>n>>r;
for(int i=0;i<=n;i++)
for(int j=0;j<=r;j++)
C[i][j]=-1;
c=0;
x=algo(n,r);
cout<<"\nThe value of "<<n<<"C"<<r<<" is "<<x;
cout<<"\nThe number of counts in dynamic programming is "<<c;
}

int ncr::algo(int n,int r)
{c++;
if(C[n][r]!=-1)
return C[n][r];
if(n==r||r==0)
return 1;
else
{
return C[n][r]=algo(n-1,r-1)+algo(n-1,r);
}
}

int main()
{ncr f;
f.input();
return 0;
}
