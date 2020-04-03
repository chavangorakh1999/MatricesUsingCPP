#include<iostream>
using namespace std;

// //Simple program to get digonal elements in matrix

// //getting the digonal element utilising space 
// void set(int a[],int i,int j, int x)
// {
// 	if(i==j)
// 		a[i-1]=x;
// }
// //show the element at position
// void get(int a[],int i,int j)
// {
// 	if(i==j)
// 		cout<<a[i-1];
// }

// int main()
// {
// 	int a[100];
// 	int i,j,x;
// 	set(a,1,1,5);
// 	get(a,1,1);


// }
class Diagonal
{
private:
	int n;
	int *A;

public:
	Diagonal(int n)
	{
		this->n=n;
		A=new int[n];

	}
	void set(int i,int j, int x);
	int get(int i, int j);
	void display();
	~Diagonal()
	{
		delete []A;
	};
};
void Diagonal::set(int i,int j,int x)
{
	if(i==j)
		A[i-1]=x;
}
int Diagonal::get(int i,int j)
{
	if(i==j)
		return A[i-1];
	else return 0;
}
void Diagonal::display()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
				cout<<A[i]<<" ";
			else
				cout<<"0"<<" ";
		}
		cout<<endl;
	}

}


int main()
{
	Diagonal d(4);
	d.set(1,1,5);
	d.set(2,2,4);
	d.set(3,3,6);
	d.set(4,4,9);
	d.display();
	return 0;
}

