//Hrishi
// Huffman Tree  using min Heap + Encoding + Decoding
#include<iostream>
#include<cstdio>
#define asize 100
using namespace std;
struct node
{
	struct node *lptr;
	struct node *rptr;
	int f;
	char c;
};

class Heap
{
 public:
 	Heap();
 	struct node B[100];
	int hsize;
	void HeapInsert(struct node &T);
	void HeapDisplay();
	struct node* Delmin();
}H;
Heap::Heap()
{
	for(int i=0;i<100;i++)
		B[i].lptr=B[i].rptr=NULL;
}
struct node *hptr;
void swap(struct node &a,struct node &b);
void HUFF_TREE();
struct node* huff_tree_insert(struct node *TEMP1,struct node *TEMP2);
void huff_tree_inorder(struct node *ptr);
void getcode(int A[],char letter,struct node *ptr,int prev_val);
void getstring(char C[]);

int main()
{
	H.hsize=0;
	int A[20],N,num,freq;
	char C[50],letter;
	struct node *temp=new struct node;
	cout<<"\n Enter the no.of distinct letters: ";
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cout<<"\n "<<i+1<<" th letter: "; 
		cin>>temp->c;
		cout<<" frequency: ";
		cin>>temp->f;
		H.HeapInsert(*temp);
	}
	H.HeapDisplay();
	HUFF_TREE();
	cout<<endl<<"\nHuffman Tree(Inorder):\n";
	huff_tree_inorder(hptr);
	cout<<endl;
	do{
		cout<<"\n\n 1.Get string for the given Hoffman code(Decoding):\n 2.Get Hoffman code for the given string (Encoding):\n 3.Exit\n Enter your choice: ";
		cin>>num;
		if(num==1)
		{
			cout<<"\n Enter the huffman code to identify string: ";
			cin>>C;
			getstring(C);
		}
		if(num==2)
		{
			cout<<"\n Enter the string to find hoffman code: ";
			cin>>C;
			for(int i=0;C[i]!='\0';i++)
				getcode(A,C[i],hptr,0);
		}

	}while(num!=3);
	cout<<endl;
	return 0;
}
void Heap::HeapInsert(struct node &T)
{
	hsize++;
	B[hsize]=T;
	int i=hsize;
	while(i>1&& B[i].f<B[i/2].f)
	{
		swap (B[i],B[i/2]);
		i=i/2;
	}
}

struct node * Heap::Delmin()
{   
	struct node *TEMP=new struct node;
	TEMP->lptr=B[1].lptr;
	TEMP->rptr=B[1].rptr;
	TEMP->c=B[1].c;
	TEMP->f=B[1].f;
	B[1]=B[hsize--];
	cout<<"\n Minimum element: "<<TEMP->f<<": "<<TEMP->c<<" got deleted";
	int i=1; int minI;
	while(2*i<=hsize)
	{
	if((2*i+1)>hsize)
		minI=2*i;
	else
	{
		if(B[2*i].f<B[2*i+1].f)
			minI=2*i;
		else 
			minI=2*i+1;
	}
	if(B[minI].f<B[i].f)
	{
		swap (B[i],B[minI]);
		i=minI;
	}
	else
		break;
	}
	return TEMP;
}

void Heap::HeapDisplay()
{	
	cout<<"\nHeap Display:\n";
	struct node *temp;
	Heap H1=H;
	for(int i=1;i<=H1.hsize;)
		temp=H1.Delmin();
	cout<<endl;
}

void HUFF_TREE()
{
	cout<<"\n Heap with sum reinsertion:\n";
	struct node *TEMP1,*TEMP2;
	while(H.hsize>1)
	{
		TEMP1=H.Delmin();
		TEMP2=H.Delmin();
		struct node *TEMP=huff_tree_insert(TEMP1,TEMP2);
		H.HeapInsert(*TEMP);
		cout<<endl;
	}
	hptr=H.Delmin();
}

struct node* huff_tree_insert(struct node *TEMP1,struct node *TEMP2)
{
	struct node *thptr=new struct node;
	thptr->lptr=TEMP1;	//always least freq will be coming to TEMP1!
	thptr->rptr=TEMP2;
	thptr->f=TEMP1->f+TEMP2->f;
	thptr->c='@';
	return(thptr);
}

void huff_tree_inorder(struct node *ptr) 
{
	if(ptr!=NULL)
	{
		huff_tree_inorder(ptr->lptr);
		cout<<"\n freq: "<<ptr->f<<" char: "<<ptr->c;
		huff_tree_inorder(ptr->rptr);
	}
}
void getstring(char C[])
{
	struct node *thptr=hptr;
	int i=0;
	cout<<"\nThe string for given code is: ";
	while(C[i]!='\0')
	{
		if(thptr->lptr==NULL&& thptr->rptr==NULL)
			{
				cout<<thptr->c;
				thptr=hptr;
				continue;
			}
		if(C[i]=='0')
			thptr=thptr->lptr;
		else if(C[i]=='1')
			thptr=thptr->rptr;
		else
			{
				cout<<"\n Invalid code";
				break;
			}
		i++;
	}
	if(thptr->lptr==NULL&& thptr->rptr==NULL)
		cout<<thptr->c;
	else
		cout<<"\n invalid Code";

}
void getcode(int A[],char letter,struct node *ptr,int prev_val)
{
	if(ptr->lptr!=NULL)
	{
		A[prev_val]=0;
		getcode(A,letter,ptr->lptr,prev_val+1);
	}
	if(ptr->rptr!=NULL)
	{
		A[prev_val]=1;
		getcode(A,letter,ptr->rptr,prev_val+1);
	}
	if(ptr->lptr==NULL&& ptr->rptr==NULL)
	{
		if(ptr->c==letter)
		{
			cout<<"\n code for "<<letter<<" is: ";
			for(int i=0;i<prev_val;i++)
				cout<<A[i];
			cout<<endl;
		}
	}
}

void swap(struct node &a,struct node &b)
{
	struct node temp=a;
	a=b;
	b=temp;
}
