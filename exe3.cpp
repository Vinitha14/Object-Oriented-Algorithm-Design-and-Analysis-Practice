#include<iostream>
#include<stdio.h>

using namespace std;

int c[5];
int i=0;

class arr
{

  int n;
  int arr[10];

  public:

  int getele(int m)
  { 
       n=m;

       int i;

       cout<<"\nWrite the elements of the array \n";

       for(i=0;i<n;i++)
       cin>>arr[i];

       cout<<endl;

  }
  
  int maximum(int a,int b)
  {

    if(a<b)
    return b;

    else return a;

   }

  int minimum(int a,int b)
  {

    if(a<b)
    return a;

    else return b;

   }

   int max(int beg,int end)
   {

       if(beg==end)
       return(arr[beg]);


       else {
               if(end==beg+1)
               {
                    c[i]=minimum(arr[beg],arr[beg+1]);
                    i=i+1;

               }


               return( maximum( max(beg, (beg+end)/2), max((beg+end)/2+1,end)));

             }

   }

   int rets()
   {
      return n;

   }

   int min(int beg,int end)
   {

       if(beg==end)
       return(c[beg]);

       else {
                return( minimum( min(beg, (beg+end)/2), min((beg+end)/2+1,end)));

             }

   }

    void copy()
    {
       int k;
     
        for(k=0;k<i;k++)
        arr[k]=c[k];

        n=i;

    }

};
       

    

int main()
{

   arr a,b;

   int n;

   cout<<"\n Enter the value of n : ";
   cin>>n;

   a.getele(n);

   cout<<"\n The Maximum is : "<<a.max(0,a.rets()-1)<<endl;

   int k;

   for(k=0;k<i;k++)
   //cout<<c[k]<<"  ";
   

   //cout<<endl;

   b.copy();


   cout<<"\n The Minimum is : "<<b.min(0,b.rets()-1)<<endl;

   return(0);

}
