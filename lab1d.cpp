#include<iostream>
#include<cmath>

using namespace std;

int n=1;

int main()
{
float i,j;
i=100*n*n;
j=pow(2,n);

for (int x=2;i>=j;x++)
	{n=x;
	i=100*n*n;
    j=pow(2,n);
	}

cout<<endl<<"Smallest Value of n :"<<n;

return(0);	
}

