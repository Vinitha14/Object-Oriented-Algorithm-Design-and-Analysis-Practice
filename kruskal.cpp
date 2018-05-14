#include<iostream>

using namespace std;


class kruskal
{
   int V,E;
   int v1,v2,w1,root;
   int count1,count2;
   int a[50][50];
   int p[50];
   int o[50][3];
   
   public:
   
     kruskal()
     {
        cout << "Enter the range of vertices: ";
        cin >> V;
       // int a[V+1][V+1];
       
       for(int i=0;i<=V;i++)
       for(int j=0;j<=V;j++)
           a[i][j] = 0;
           
       for(int i=0;i<=V;i++)
         p[i]=-1;
         
       count2=0;
       
     }
     void inputGraph();
     void minInGraph();
     int findRoot(int x);
     void algo();
     void display();
 
};

void kruskal::inputGraph()
{
   cout << "Enter the number of edged u want to enter: ";
   cin >> E;
   
   count1=E;
   
   int v1,v2,w;
   
   for(int i=1;i<=E;i++)
   {
      cout << "Enter the vertices between which u want to enter edge and corresponding edge: ";
      cin >> v1 >> v2 >> w;
      a[v1][v2]=w;
     // a[v2][v1]=w;
      
   }

  /* for(int i=0;i<=V;i++)
   {
     for(int j=i;j<=V;j++)
     {
       cout << a[i][j] << "  ";
     }
     cout << endl;
    }*/
}

void kruskal::minInGraph()
{
  int mi=99999;
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
  //cout << "MIN: " << mi <<  " v1,v2: " << v1 << v2 << endl;
}

int kruskal::findRoot(int x)
{
  int root=x;
  while(p[root]>=0)
     root=p[root];
     
  
  return(root);
}

void kruskal::algo()
{
 int i=0;
 while(count1>0 && count2<=V-1)
 {
  minInGraph();
  a[v1][v2]=0;
  count1--;
  int r1=findRoot(v1);
  int r2=findRoot(v2);
   
  //cout << "Root of v1: " << r1 << ", Root of v2: " << r2 <<endl;
  
  if(r1!=r2)
  {
    if(p[r1]*-1>=p[r2]*-1)
    {
      p[r1]=p[r1]+p[r2];
      p[r2]=r1;
    }
    else
    {
      p[r2]=p[r1]+p[r2];
      p[r1]=r2;
    }
    
    o[count2][0]=v1;
    o[count2][1]=v2;
    o[count2][2]=w1;
    
    count2++;
  }
  /*for(int i=0;i<=V;i++)
     cout << p[i] << "  ";
   cout << endl;*/
 }
 
 
  
}


void kruskal::display()
{
  for(int i=0;i<count2;i++)
  {
    cout << o[i][0] << "---" << o[i][1] << "w== " << o[i][2] << endl;
  }
  
}

int main()
{
   kruskal obj;
   obj.inputGraph();
   //obj.minInGraph();
   //int z=obj.findRoot(2);
   //cout << "root: " << z << endl;
   obj.algo();
   obj.display();
   
}
