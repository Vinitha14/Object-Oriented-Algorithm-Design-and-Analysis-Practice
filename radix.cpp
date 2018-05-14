#include<iostream>
#include<cstring>
using namespace std;

class radix
{
  private:

  
  string a[100];

  public:
  int k,n;
 void read()
 {
  cout<<"enter no of characters in the array"<<endl;
  cin>>n;
  cout<<"enter size of each string"<<endl;
  cin>>k;
  cout<<"enter strings"<<endl;
  for(int i=0;i<n/k;i++)
     cin>>a[i];
 }
  void countsort(int j);
  void radixsort();
};

void radix::countsort(int j)
{
 int f[26],c[26],temp1,sum=0,temp2;
 string o[n/k];
 
  for(int i=0;i<26;i++)
   c[i]=f[i]=0;

 for(int i=0;i<n/k;i++)
  {
    temp1=a[i][j]-97;
    f[temp1]++;
  }

 for(int i=0;i<26;i++)
 {
  sum=sum+f[i];
  c[i]=sum;
 }

 for(int i=(n/k)-1;i>=0;i--)
 {
  temp2=a[i][j]-97;
  o[--c[temp2]]=a[i];
 }
 
 for(int i=0;i<n/k;i++)
   a[i]=o[i];

 for(int i=0;i<n/k;i++)
  cout<<" "<<a[i]<<endl;

 cout<<"--------"<<endl;
  
}
    
 
 void radix::radixsort()
{
  for(int j=k-1;j>=0;j--)
   countsort(j);
 } 


int main()
{
 radix obj;
 obj.read();
 obj.radixsort();

 return(0);
}



