#include<iostream>
using namespace std;


class LowerTriangular
{
private:
	int n;
	int *A;

public:
	LowerTriangular()
	{
		n=2;
		A=new int[2*(2+1)/2];

	}
	LowerTriangular(int n)
	{
		this->n=n;
		A=new int[n*(n+1)/2];

	}
	void set(int i,int j, int x);
	int get(int i, int j);
	void display();
	~LowerTriangular()
	{
		delete []A;
	};
};
void LowerTriangular::set(int i,int j,int x)
{
	if(i>=j)
		A[n*(j-1)-(j-2)*(j-1)/2+i-j]=x;
}
int LowerTriangular::get(int i,int j)
{
	if(i>=j)
		return A[n*(j-1)-(j-2)*(j-1)/2+i-j];
	else return 0;
}
void LowerTriangular::display()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i>=j)
				cout<<A[n*(j-1)-(j-2)*(j-1)/2+i-j]<<" ";
			else
				cout<<"0"<<" ";
		}
		cout<<endl;
	}

}


int main()
{
	int d;
	cout<<"Enter Dimension:";
	cin>>d;
	LowerTriangular lt(d);
	
	int x;
	cout<<"Enter Elements:"<<endl;
	for(int i=1;i<=d;i++)
	{
		for(int j=1;j<=d;j++)
		{
			cin>>x;
			lt.set(i,j,x);
		}
	}
	lt.display();

	return 0;
}

