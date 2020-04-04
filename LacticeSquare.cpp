
#include<iostream>
using namespace std;


class Diagonal
{
private:
  int n;
  int *A;
    int sum;
    

public:
  
  Diagonal(int n)
  {
    this->n=n;
    A=new int[n*n];
      sum=0;

  }
  int Sum();
  void set(int i,int j,int x,int d);
  int get(int i, int j);
    void DupliInRow()
    {int k,rep=0,max;
      int *h;
      k=0;
      while(k<n*n)
      {
      max=A[0];
      for(int i=k;i<n;i++)
      {
        if(max<A[i])
        {
          max=A[i];
        }
      }
      h=new int[max];
      for(int i=k;i<n;i++)
      {
        h[A[i]]++;
      }
      for(int i=0;i<max;i++)
      {
        if(h[i]<1)
        {
          rep=rep+1;
          break;
        }
      }
      k=k+n;
    }
    cout<<rep;

    };
    void DupliInCol();
    
  void display();
  ~Diagonal()
  {
    delete []A;
  };
};
int  Diagonal::Sum()
{
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
         if(i==j)
         sum=sum + A[n*(i-1)+(j-1)];
      }
    }
    return sum;
  
}
void Diagonal::set(int i,int j,int l,int d)
{

    A[d*(i-1)+j-1]=l;
}


void Diagonal::display()
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      //if(i==j)
        cout<<A[n*(i-1)+(j-1)]<<" ";
      // else
      //   cout<<"0"<<" ";
    }
    cout<<endl;
  }

}


int main()
{
  int x,d,l;
     
  
  cout<<"NO of Matrix:";
  cin>>x;
    
    
  while(x>0)

  {
    cout<<"Dimension:";
    cin>>d;
   Diagonal lm(d);
    for(int i=0;i<d;i++)
    {
      for(int j=0;j<d;j++)
      {
        cout<<"Enter Element:";
        cin>>l;
        lm.set(i,j,l,d);
      }
      
    }
    x--;
      lm.display();
      cout<<lm.Sum();
      lm.DupliInRow();
      cout<<endl;
  
  }

  
  
  
  return 0;
}



