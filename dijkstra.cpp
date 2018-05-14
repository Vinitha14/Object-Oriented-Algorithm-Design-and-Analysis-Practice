#include <iostream>

using namespace std;

class dijkstra
{
  int a[50][50];
  int d[50];
  int m[50];
  int pre[20];
  int V,E,s;
  
  public:
    dijkstra()
    {
       cout << "Enter the range of vertices: ";
       cin >> V;
       
       for(int i=1;i<=V;i++)
          for(int j=0;j<=V;j++)
             a[i][j]=999;
       for(int i=1;i<=V;i++)
           d[i]=999;
       for(int i=1;i<=V;i++)
           m[i]=-1;
       for(int i=1;i<=V;i++)
           pre[i]=-1;
                                                                                                                           
    }
    void inputGraph();
    void display();
    void algo();
    void displayOutput();
};

void dijkstra::inputGraph()
{
   cout << "Enter the number of edges u want to enter: ";
   cin >> E;
   
   int v1,v2,w;
   
   for(int i=0;i<E;i++)
   {
     cout << "Enter the vertices between which u want to enter edge and corresponding cost: ";
     cin >> v1 >> v2 >> w;
     a[v1][v2]=w;
   }
}

void dijkstra::display()
{
   for(int i=1;i<=V;i++)
   {
     for(int j=1;j<=V;j++)
         cout << a[i][j] << " ";
     cout << endl;
   }
}

void dijkstra::algo()
{
   cout << "Enter the source vertex: ";
   cin >> s;
   
   for(int i=1;i<=V;i++)
   {
      d[i]=a[s][i];
      m[i]=0;
   }
   for(int i=1;i<=V;i++)
     pre[i]=s;
   d[s]=0;
   m[s]=1;
   pre[s]=-1;
   
   int min=9999;
   int u,w;
   
   for(int i=2;i<=V;i++)
   {
    min=9999;
      for(int j=1;j<=V;j++)
      {
         if(d[j]<min && m[j]==0)
         {
            min=d[j];
            u=j;
           // cout << "Min:" << min << "  U: " << u << endl;
         }
      }

      m[u]=1;
      
      for(int j=1;j<=V;j++)
      {
        if(a[u][j]!=0)
            w=j;
        if(m[w]==0)
        {
           if(d[w]>d[u]+a[u][w])
           {
              d[w]=d[u]+a[u][w];
              pre[w]=u;
           }
        }
        
      }
      
 
   }
}

void dijkstra::displayOutput()
{
  for(int i=1;i<=V;i++)
  {
    cout << endl;
    cout << " Index: " << i << " Dist: " << d[i] << "  Path: ";
    int j=i;
    while(pre[j]!=-1)
    {
       cout << j << "<--";
       j=pre[j];  
    }
    cout << s << endl;
  }
  
}

int main()
{
   dijkstra obj;
   obj.inputGraph();
  // obj.display();
   obj.algo();
   obj.displayOutput();
}
