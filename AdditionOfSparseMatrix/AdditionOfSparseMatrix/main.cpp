//
//  main.cpp
//  AdditionOfSparseMatrix
//
//  Created by Gorakh Chavan on 07/04/20.
//  Copyright © 2020 Gorakh Chavan. All rights reserved.
//

#include <iostream>
using namespace std;

struct element
{
public:
    int i;
    int j;
    int x;
};
class SparseMatrix
{
private:
    int m;
    int n;
    int num;
    struct element *e;
public:
    SparseMatrix(int m,int n,int num)
    {
        this->m=m;
        this->n=n;
        this->num=num;
        e=new element[this->num];
    }
    ~SparseMatrix()
    {
        delete [] e;
    }
    SparseMatrix operator+(SparseMatrix &s);
    friend istream & operator >>(istream &is,SparseMatrix &s);
    friend ostream &operator <<(ostream &os,SparseMatrix &s);
};

SparseMatrix SparseMatrix::operator+(SparseMatrix &s)
{
    int i,j,k;
    if(m!=s.m || n!=s.n)
    {
        cout<<"Operations cannot be performed";
    }
    SparseMatrix *sum=new SparseMatrix(n,m,num+s.num);
    
    i=j=k=0;
    while(i<num &j<s.num)
    {
        
        if(e[i].i<s.e[j].i)
            sum->e[k++]=e[i++];
        else if(e[i].i>s.e[j].i)
            sum->e[k++]=s.e[j++];
        else
        {
            if(e[i].j<s.e[j].j)
                sum->e[k++]=e[i++];
            else if(e[i].j>s.e[j].j)
                sum->e[k++]=s.e[j++];
            else
            {
                sum->e[k]=e[i];
                sum->e[k++].x=e[i++].x+s.e[j++].x;
            }
        }
        
        
    }
    for(;i<num;i++)sum->e[k++]=e[i];
    for(;j<s.num;j++)sum->e[k++]=s.e[j];
    sum->num=k;
    return *sum;
}


istream & operator >>(istream &is,SparseMatrix &s)
    {

        cout<<"Enter all elements ";
        for(int i=0;i<s.num;i++)
        {
            cin>>s.e[i].i>>s.e[i].j>>s.e[i].x;
        }
        
        return is;
    }


ostream &operator <<(ostream &os,SparseMatrix &s)
{
    int i,j,k=0;
    for (i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if(i==s.e[k].i && j==s.e[k].j)
            {
                cout<<s.e[k].x<<" ";
                k++;
            }
            else
            {
                cout<<"0"<<" ";
                
            }
        }
        cout<<endl;
    }
    return os;
}

int main()
{
    SparseMatrix s1(5,5,5);
    SparseMatrix s2(5,5,5);
    
    cin>>s1;
    cin>>s2;
    SparseMatrix sum=s1+s2;
    
    cout<<"First matrix"<<endl<<s1;
    cout<<"second Matrix"<<endl<<s2;
    cout<<"Sum matrix"<<endl<<sum;
    
    
    
    return 0;
}
