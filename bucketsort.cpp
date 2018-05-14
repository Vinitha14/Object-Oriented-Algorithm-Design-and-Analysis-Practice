#include <iostream>
#include<cstdlib>

using namespace std;

struct node
{
int rno;
char name[20];
float marks;
struct node *nptr;
};

struct node *b[20]={NULL};
struct node *t[20]={NULL};


class bucket
{
int i,k,a[20];
public:
void read();
void insert();
void disp();
};

void bucket::read()
{
cout<<"\nEnter the range of Roll numbers: ";
cin>>k;
}

void bucket::insert()
{
struct node * newnode= (struct node *) malloc (sizeof(struct node));
cout<<"\nEnter the name,roll number and mark of student: ";
cin>>newnode->name>>newnode->rno>>newnode->marks;
newnode->nptr=NULL;
if(b[newnode->rno]==0)
{b[newnode->rno]=newnode;
t[newnode->rno]=newnode;
}
else
{t[newnode->rno]->nptr=newnode;
t[newnode->rno]=newnode;
}
}

void bucket::disp()
{
struct node * mynode;
for(i=0;i<k;i++)
{mynode=b[i];
	if(mynode==NULL)
	continue;
	else
		{
		while(mynode!=NULL)
				{
				cout<<"\nName: "<<mynode->name<<"\tRoll no: "<<mynode->rno<<"\tMarks: "<<mynode->marks;
				mynode=mynode->nptr;
				}
		}
}	
}

int main()
{
int n;
cout<<"\nEnter the number of students: ";
cin>>n;
bucket obj;
obj.read();
for(int i=0;i<n;i++)
obj.insert();
obj.disp();
}

