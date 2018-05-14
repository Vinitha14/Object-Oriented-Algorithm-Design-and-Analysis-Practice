#include<iostream>
using namespace std;
class mcsss
{
public:
	int a[100];
	int st;
	int en;
	int msum;
	int n;
	void input()
	{
		cout<<"Enter no. of Elements-";
		cin>>n;
		cout<<"Enter Elements-\n";
		for (int i = 0; i < n; i++)
		{
			cin>>a[i];
		}
		cout<<"\nThe sequence is -:\n";
		for (int i = 0; i < n; i++)
		{
			cout<<a[i]<<" ";
		}
	}
	void seq()
	{
		int sum=0;
		msum=0;
		st=0;
		en=0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				sum=0;
				for (int k = i; k < j; k++)
				{
					sum=sum+a[k];
					if (msum < sum)
					{
						msum=sum;
						st=i;
						en=k;
					}
				}
			}
		}
		cout<<"\n\nThe max subsequence is-\n";
		for (int i = st; i <=en ; i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<"\nMax sum = "<<msum<<" ";
	}
};

int main()
{
	class mcsss obj;
	obj.input();
	obj.seq();
}