#include<iostream>
using namespace std;


class LowerTriangularMatrix
{
private:
	int n;
	int *A;

public:
	LowerTriangularMatrix()
	{
		n=2;
		A=new int[2*(2+1)/2];

	}
	LowerTriangularMatrix(int n)
	{
		this->n=n;
		A=new int[n*(n+1)/2];

	}
	void set(int i,int j, int x);
	int get(int i, int j);
	void display();
	~LowerTriangularMatrix()
	{
		delete []A;
	};
};
void LowerTriangularMatrix::set(int i,int j,int x)
{
	if(i>=j)
		A[i*(i-1)/2+(j-1)]=x;
}
int LowerTriangularMatrix::get(int i,int j)
{
	if(i>=j)
		return A[i*(i-1)/2+(j-1)];
	else return 0;
}
void LowerTriangularMatrix::display()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i>=j)
				cout<<A[i*(i-1)/2+(j-1)]<<" ";
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
	LowerTriangularMatrix lt(d);
	
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

