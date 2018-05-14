#include<iostream>
#include<cstring>
using namespace std;

class str{

public:
char name[100];


};
void radixsort(str obj[],int m,int n);
class str b;
int main()
{
int n,m,i;
cout<<"\nEnter no of characters in each string:";
cin>>n;
cout<<"\nEnter no of strings: ";
cin>>m;
class str obj[m];


for(i=0;i<m;i++)
{
cout<<"\nEnter the string "<<i+1<<" :";
cin>>obj[i].name;
}
radixsort(obj,m,n);
cout<<"\nAfter sorting:"<<endl;
for(i=0;i<m;i++)
cout<<obj[i].name<<endl;
return(0);
}

void radixsort(str obj[],int m,int n)
{int i,j;
for(j=n-1;j>=0;j--)
{
str o[m];
int i,c[26]={0};
for(i=0;i<m;i++)
c[(obj[i].name[j])-97]++;
for(i=1;i<26;i++)
c[i]=c[i]+c[i-1];
for(i=m-1;i>=0;i--){
o[c[(obj[i].name[j])-97]-1]=obj[i];
c[(obj[i].name[j])-97]--;
}
for(i=0;i<m;i++)
obj[i]=o[i];
}


}



