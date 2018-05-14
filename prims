#include<iostream>
using namespace std;

class prim
{
  private:
   int cost[20][20],T[20][20],near[20];
  
  public:
  int n,m;
  void read();
  void display();
  prim();
  void prims_algo();


};

prim::prim()
{
 for(int i=1;i<=20;i++)
 for(int j=1;j<=20;j++)
   cost[i][j]=5000;
 
}





void prim::read()
{
 int i,j,k,w;
 cout<<"Enter no of vertices\n";
 cin>>n;
 cout<<"Enter no of edges\n";
 cin>>m;
 cout<<"Enter vertices and weights respectively\n";
 for(k=1;k<=m;k++)
 {
  cin>>i>>j>>w;
  cost[i][j]=w;
  cost[j][i]=w;
 }
}



void prim::display()
{
 for(int i=1;i<=n;i++)
 {
 for(int j=1;j<=n;j++)
 {
  cout<<cost[i][j]<<"\t";
 }
 cout<<endl;
 }
}


void prim::prims_algo()
{
 int minI=1000,k,l,t,p,x;
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   if(cost[i][j]!=0 && cost[i][j]<minI)  //finding first minimum
   {
    minI=cost[i][j];
    k=i;
    l=j;
   }

   T[1][1]=k;
   T[1][2]=l;
 for(int i=1;i<=n;i++)
 {
   if(cost[i][k]<cost[i][l])
     near[i]=k;
   else
    near[i]=l;
 }

 near[k]=0;
 near[l]=0;

 
 for(int i=2;i<=n-1;i++)
 {
   int minimum=10000;
    for(int s=1;s<=n;s++)   //finding minimum
    {
      if(near[s]!=0)
      {
        if(cost[s][near[s]]<=minimum)
        {
          minimum=cost[s][near[s]];
          x=near[s];
          p=s;
          cout<<"\nprinting minimum\n"<<x<<"\t"<<p<<endl;
   
        }
      }
    }                         //for ends
  
   near[p]=0;



   for(t=1;t<=n;++t)         //updating near array
   {
    if(near[t]!=0)
    {
      if(cost[t][near[t]]>cost[t][p])
         near[t]=p;
    }

   }

   T[i][1]=x;
   T[i][2]=p;
  
   
 }


 cout<<"\nEdges in the tree\n";
 for(int i=1;i<=n-1;i++)
 {
   cout<<T[i][1]<<"-->"<<T[i][2]<<endl;
 }



}


int main()
{
 prim obj;
 obj.read();
 obj.display();
 obj.prims_algo();

return(0);
}

