#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;


int partition(int arr[],int l,int r,int x);
int kthsmall(int arr[],int l,int r,int k);
struct student
{
  int rno;
  char name[10];
  int CTC;
}s[10];


int fm(int arr[],int n)
{
  sort(arr,arr+n);
  return arr[n/2];
}
  int kthsmall(int arr[],int l,int r,int k)
   {
     if(k>0 && k<=r-l+1)
       {
          int n=r-l+1,i;
          int median[n+4/5];
          for(i=0;i<n/5;i++)
             median[i]=fm(arr+l+i*5,5);
          if(i*5<n)
             {
               median[i]=fm(arr+l+i*5,n%5);
               i++;
             }
          int mom;
          if(i==1)
              mom=median[i-1];
          else
              mom=kthsmall(median,0,i-1,i/2);
      
      int pos=partition(arr,l,r,mom);
      if(pos-l==k-1)
          return arr[pos];
      else  if(pos-l>k-1)
          return kthsmall(arr,l,pos-1,k);
      else
          return kthsmall(arr,pos+1,r,k-pos+l-1);
   }
  return INT_MAX;
}

void swap(int *a,int *b)
{
  int temp=*a;
   *a=*b;
   *b=temp;
}

int partition(int arr[],int l,int r,int x)
{
  int i,j;
   for(i=l;i<r;i++)
      if(arr[i]==x)
          break;
   swap(&arr[i],&arr[r]);
   i=l;
   for( j=l;j<=r-1;j++)
   {
      if(arr[j]<=x)
         {
           swap(&arr[i],&arr[j]);
           i++;
         }
   }
  swap(&arr[i],&arr[j]);
  return i;
}
int main()
{
  int arr[100],k;
  cout<<"\nEnter the number of students: ";
  int n,i;
  cin>>n;
 
 for(int i=0;i<n;i++)
 {
cout<<"\nEnter students details (Roll no, Name, CTC): ";
cin>>s[i].rno>>s[i].name>>s[i].CTC;
}
for(i=0;i<n;i++)
{
  arr[i]=s[i].CTC;
}


int minctc;
cout<<"\nMinCTC="<<kthsmall(arr,0,n-1,1);
int maxctc;
cout<<"\nMaxCTC="<<kthsmall(arr,0,n-1,n);
int medctc;
cout<<"\nMedCTC=";
if(n%2!=0)
 {
   cout<<kthsmall(arr,0,n-1,(n+1)/2);
 }
else
  {
    cout<<kthsmall(arr,0,n-1,n/2);
  }
return (0);
}
