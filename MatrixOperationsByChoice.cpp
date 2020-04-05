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
	//instead of space we can put Another Required Formule to perform task 
		A=new int[n*(n+1)/2];

	}
	void set(int i,int j, int x);
	int get(int i, int j);
	void display();
	void  create();
	~LowerTriangular()
	{
		delete []A;
	};
};
void LowerTriangular::create()
{
	for(int i=1;i<=n*(n+1)/2;i++)
				{
					cin>>A[i-1];
				}
}
void LowerTriangular::set(int i,int j,int x)
{
	if(i>=j)
		A[i*(i-1)/2+(j-1)]=x;
}
int LowerTriangular::get(int i,int j)
{
	if(i>=j)
		//And Make changes to the place where they are recieved and retervied from
		return A[i*(i-1)/2+(j-1)];
	else return 0;
}
void LowerTriangular::display()
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
	int ch,d,x,j,i;
	char q;
	cout<<"Enter dimension:";
	cin>>d;
	LowerTriangular lt(d);
	do
	{
		cout<<"----MENU------"<<endl;
		cout<<"1.Create"<<endl;
		cout<<"2.Get"<<endl;
		cout<<"3.Set"<<endl;
		cout<<"4.Display"<<endl;
		cin>>ch;

		switch(ch)
		{
			case 1:cout<<"Enter Digonal elements:";
				lt.create();
				break;

			case 2:cout<<"Enter Row,Column:";
				   cin>>i>>j>>x;
				   lt.get(i,j);
				   break;
			case 3:cout<<"Enter Row,Column,Value :";
					cin>>i>>j>>x;
					lt.set(i,j,x);
					break;
			case 4:cout<<"This is matrix"<<endl;
				   lt.display();
				   break;
			default:cout<<"Invalid Input--->";
					break;


		}
		cout<<"Do you want to continue y/n:";
		cin>>q;

	// cout<<"Enter Dimension:";
	// cin>>d;

}while(q=='y');

	return 0;
}

