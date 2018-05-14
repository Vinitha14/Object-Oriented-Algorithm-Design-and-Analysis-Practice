#include <iostream>

using namespace std;

class bellman
{
   int a[50][50];
   int b[50];
   int V,E,s;
   int v1, v2, w;
   int sum;
   
   public: 
      bellman()
      {
         cout << "Enter the range of vertices: ";
         cin >> V;
         
         for(int i=1;i<=V;i++)
            for(int j=1;j<=V;j++)
               a[i][j]=999;
    
         for(int i=1;i<=V;i++)
             b[i]=999;
             
        cout << "Enter the source vetex: ";
        cin >> s;
        b[s]=0;
      }
      void inputGraph();
      void display();
      void algo();
      void displayOutput();
      
};

void bellman::inputGraph()
{
   cout << "Enter the number of edges: ";
   cin >> E;
   
   for(int i=0;i<E;i++)
   {
      cout << "Enter the vertices and edge between them: ";
      cin >> v1 >> v2 >> w;
      a[v1][v2]=w;
   }
}

void bellman::display()
{
   for(int i=1;i<=V;i++)
   {
      for(int j=1;j<=V;j++)
         cout << a[i][j] << " ";
      cout << endl;
   }
}

void bellman::displayOutput()
{
  cout << endl ;
   for(int i=1;i<=V;i++)
   {
     cout << b[i] << " "; 
   }
}


void bellman::algo()
{
for(int k=0;k<E;k++)
{
   for(int i=1;i<=V;i++)
   {
      for(int j=1;j<=V;j++)
      {
          if(a[i][j]!=999)
          {  
              sum=b[i]+a[i][j];
              if(sum<b[j])
                   b[j]=sum;
          // cout << i << " " << j << " " << sum << endl;
          }          
      }
      //cout << endl;
   }
}
}


int main()
{
   bellman obj;
   obj.inputGraph();
   obj.display();
   obj.algo();
   obj.displayOutput();
}

