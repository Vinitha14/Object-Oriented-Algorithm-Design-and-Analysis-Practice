#include<iostream>
#include<cstdio>
#include<stdlib.h>

using namespace std;

int n;

struct MinHN
{
char d;
int f;
struct MinHN *right;
struct MinHN *left;
};

struct MinH
{
unsigned size;
unsigned capacity;
struct MinHN **array;
};

class huffman
{
public:
char data[20];
int freq[20];
void read();
void write();
struct MinHN* newNode(char d,int f); 
struct MinH* createMinH();
void swap(struct MinHN **a,struct MinHN **b);
void minHeapify(struct MinH* minH,int x);
int isSizeOne(struct MinH* minH);
struct MinHN* extractMin(struct MinH* minH);
void insert(struct MinH* minH,struct MinHN* minHN);
void buildMinH(struct MinH* minH);
void printArr(int arr[],int n);
int isLeaf(struct MinHN* root);
struct MinH* createandbuildMH();
struct MinHN* buildHuffmanTree();
void printcodes(struct MinHN* root,int arr[],int top);
void HuffmanCodes();
};

void huffman::read()
{
cout<<"\nEnter the number of characters: ";
cin>>n;
for(int i=0;i<n;i++)
{cout<<"\nEnter the character: ";
cin>>data[i];
cout<<"\nEnter the frequency: ";
cin>>freq[i];}
}

void huffman::write()
{
for(int i=0;i<n;i++)
{cout<<"\n"<<data[i]<<" ";
cout<<freq[i];}
}

struct MinHN* huffman::newNode(char d,int f)
{
struct MinHN* temp=(struct MinHN*) malloc (sizeof(struct MinHN));
temp->left=temp->right=NULL;
temp->d=d;
temp->f=f;
return temp;
}

struct MinH* huffman::createMinH()
{
struct MinH* minH=(struct MinH*) malloc (sizeof(struct MinH));
minH->size=0;
minH->capacity=n;
minH->array=(struct MinHN **) malloc (minH->capacity * sizeof(struct MinHN*));
return minH;
}

void huffman::swap(struct MinHN **a,struct MinHN **b)
{
struct MinHN *t=*a;
*a=*b;
*b=t;
}

void huffman::minHeapify(struct MinH* minH,int x)
{
int smallest=x;
int left=2*x+1;
int right=2*x+2;
if(left<minH->size && minH->array[left]->f<minH->array[smallest]->f)
smallest=left;
if(right<minH->size && minH->array[right]->f<minH->array[smallest]->f)
smallest=right;
if(smallest!=x)
{swap (&minH->array[smallest],&minH->array[x]);
minHeapify(minH,smallest);
}
}

int huffman::isSizeOne(struct MinH* minH)
{
return(minH->size==1);
}

struct MinHN* huffman::extractMin(struct MinH* minH)
{
struct MinHN* temp=minH->array[0];
minH->array[0]=minH->array[minH->size-1];
--minH->size;
minHeapify(minH,0);
return temp;
}

void huffman::insert(struct MinH* minH,struct MinHN* minHN)
{
++minH->size;
int i=minH->size-1;
while(i && minHN->f <minH->array[(i-1)/2]->f)
{
minH->array[i]=minH->array[(i-1)/2];
i=(i-1)/2;
}
minH->array[i]=minHN;
}

void huffman::buildMinH(struct MinH* minH)
{
int n=minH->size-1;
int i;
for(i=(n-1)/2;i>=0;i--)
minHeapify(minH,i);
}

void huffman::printArr(int arr[],int n)
{
int i;
for(i=0;i<n;i++)
cout<<"\n"<<arr[i];
}

int huffman::isLeaf(struct MinHN* root)
{
return !(root->left) && !(root->right);
}

struct MinH* huffman::createandbuildMH()
{
struct MinH* minH=createMinH();
for(int i=0;i<n;i++)
minH->array[i]=newNode(data[i],freq[i]);
minH->size=n;
buildMinH(minH);
return minH;
}

struct MinHN* huffman::buildHuffmanTree()
{
struct MinHN* left,*right,*top;
struct MinH* minH=createandbuildMH();
while(!isSizeOne(minH))
{
left=extractMin(minH);
right=extractMin(minH);
top=newNode('$',left->f+right->f);
top->left=left;
top->right=right;
insert(minH,top);
}
return extractMin(minH);
}

void huffman::printcodes(struct MinHN* root,int arr[],int top)
{
if(root->left)
{
arr[top]=0;
printcodes(root->left,arr,top+1);
}
if(root->right)
{arr[top]=1;
printcodes(root->right,arr,top+1);
}
if(isLeaf(root))
{
cout<<root->d<<endl;
printArr(arr,top);
}
}

void huffman::HuffmanCodes()
{
struct MinHN* root=buildHuffmanTree();
int arr[100],top=0;
printcodes(root,arr,top);
}

int main()
{
huffman c;
c.read();
c.write();
c.HuffmanCodes();
return 0;
}


