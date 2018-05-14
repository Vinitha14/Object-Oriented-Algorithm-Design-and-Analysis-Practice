#include<iostream>

using namespace std;

class prims
{
   int V,E;
   int v1,v2,w1,root;
   int count1,count2;
   int a[50][50];
   int near[50];
   int o[50][3];
   
   public:
   
     prims()
     {
        cout << "Enter the range of vertices: ";
        cin >> V;
              
       for(int i=0;i<=V;i++)
       for(int j=0;j<=V;j++)
           a[i][j] = 9999;
           
       for(int i=0;i<=V;i++)
         near[i]=-1;
         
       count2=0; 
     }
     void inputGraph();
     void mincostedge();
     void algo();
     void display();
 
};

void prims::inputGraph()
{
   cout << "Enter the number of edges: ";
   cin >> E;
   
   count1=E;
   
   int v1,v2,w;
   
   for(int i=1;i<=E;i++)
   {
      cout << "Enter vertice 1,vertice 2 and corresponding edge: ";
      cin >> v1 >> v2 >> w;
      a[v1][v2]=w;
      
   }
}

void prims::mincostedge()
{
  int mi=9999;
  for(int i=0;i<=V;i++)
  {
     for(int j=0;j<=V;j++)
     {
        if(mi>=a[i][j] && a[i][j]!=0)
        {
           mi=a[i][j];
           v1=i;
           v2=j;
           w1=mi;
        }
     }
  }
}

void prims::algo()
{
 int i=0;
 while(count1>0 && count2<=V-1)
 {
  mincostedge();
  a[v1][v2]=9999;
  count1--;
  o[count2][0]=v1;
  o[count2][1]=v2;
  o[count2][2]=w1;
  count2++;
  for(int i=1;i<=V;i++)
  if(o[i][v1]<o[i][v2])
  near[i]=v1;
  else
  near[i]=v2;
  near[v1]=0;
  near[v2]=0;
  
  for(int i=2;i<=V-1;i++)
  {
  mincostedge();
  a[v1][v2]=9999;
  count1--;
  for(int t=1;t<=V;t++)
  if(near[t]!=0)
  {
  if(a[t][near[t]]>a[t][v2])
  near[t]=v2;
  }
  o[i][1]=v1;
  o[i][2]=v2;
  }
   
  count2++;
  }
}
 

void prims::display()
{
  for(int i=0;i<count2;i++)
  {
    cout << o[i][0] << "---" << o[i][1] << "w== " << o[i][2] << endl;
  }
  
}

int main()
{
   prims obj;
   obj.inputGraph();
   obj.algo();
   obj.display();
   
}
