#include<iostream>

using namespace std;

int ch;

class Arr
{int B[50];
int n;

public:
void create()
{cout<<endl<<"Enter the size of the array:";
cin>>n;
cout<<endl<<"Enter the elements of the array:";
for(int i=0;i<n;i++)
cin>>B[i];
for(int i=0;i<n;i++)
for(int j=0;j<n-i-1;j++)
if(B[j]>B[j+1])
{int temp=B[j];
B[j]=B[j+1];
B[j+1]=temp;}
}

void insert(int z)
{n++;
B[n-1]=z;
for(int i=0;i<n;i++)
for(int j=0;j<n-i-1;j++)
if(B[j]>B[j+1])
{int temp=B[j];
B[j]=B[j+1];
B[j+1]=temp;}
}

void search(int x)
{int flag=0;
for(int i=0;i<n;i++)
if(B[i]==x)
{cout<<endl<<"Element found in "<<i+1<<"th position!";
flag=1;}
if(flag==0)
cout<<endl<<"Element not found!";
}

void del(int y)
{int flag=0;
for(int i=0;i<n;i++)
if(B[i]==y)
{for(int j=i;j<n-1;j++)
B[j]=B[j+1];
cout<<endl<<"Element is deleted!";
n--;
flag=1;
}
if(flag==0)
cout<<endl<<"Element not found to be deleted!";
}

void disp()
{
cout<<endl<<"Array displayed in ascending order:";
for(int i=0;i<n;i++)
cout<<B[i]<<" ";
}

};

int main()
{
Arr A;
do
{cout<<endl<<"1.Create\n2.Insert\n3.Search\n4.Delete\n5.Display\n6.Exit";
cout<<endl<<"Enter your choice:";
cin>>ch;
if(ch==1)
A.create();
else if(ch==2)
{int x;
cout<<endl<<"Enter the element to be inserted:";
cin>>x;
A.insert(x);
}
else if(ch==3)
{int y;
cout<<endl<<"Enter the element to be searched:";
cin>>y;
A.search(y);
}
else if(ch==4)
{int z;
cout<<endl<<"Enter the element to be deleted:";
cin>>z;
A.del(z);
}
else if(ch==5)
A.disp();
}while(ch!=6);

return(0);
}
