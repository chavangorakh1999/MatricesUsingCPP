//
//  main.cpp
//  Polynomial
//
//  Created by Gorakh Chavan on 08/04/20.
//  Copyright © 2020 Gorakh Chavan. All rights reserved.
//

#include <iostream>
using namespace std;
struct term

{
    int coefficiant;
    int exponent;
};
class polynomial
{
private:
    int n;
    struct term *terms;
public:
    polynomial(int n)
    {
        this->n=n;
        terms=new term[n];
    }
    ~polynomial()
    {
        delete [] terms;
    }
    polynomial operator +(polynomial &p);
    friend istream & operator >>(istream &is,polynomial &p);
    friend ostream & operator <<(ostream &os,polynomial &p);
    
};
    istream & operator >>(istream &is,polynomial &p)
    {
        cout<<"Enter No of terms";
        cin>>p.n;
        for(int i=0;i<p.n;i++)
        {
            cin>>p.terms[i].coefficiant>>p.terms[i].exponent;
        }
        return is;
    }
    ostream & operator <<(ostream &os,polynomial &p)
    {
        for(int i=0;i<p.n;i++)
        {
            cout<<p.terms[i].coefficiant<<" "<<p.terms[i].exponent<<"||";
        }
        return os;
    }
    polynomial polynomial::operator+(polynomial &p)
    {
        int i,k,j;
        i=j=k=0;
        polynomial *sum=new polynomial(n+p.n);
        while(i<n && j<p.n)
        {
         if(terms[i].exponent>p.terms[j].exponent)
        {
            sum->terms[k++]=terms[i++];
        }
        else if(terms[i].exponent<p.terms[j].exponent)
        {
            sum->terms[k++]=p.terms[j++];
            
        }
        else
        {
            sum->terms[k]=terms[i];
            sum->terms[k].coefficiant+=p.terms[j].coefficiant;
            i++;
            j++;
            k++;
        }
            
        
        }
        for(;i<n;i++)sum->terms[k++]=terms[i];
        for(;j<p.n;j++)sum->terms[k++]=p.terms[j];
        sum->n=k;
        return *sum;
    }



int main()
{
    polynomial p(5);
    polynomial p1(5);
    cin>>p;
    cin>>p1;
    polynomial sum=p+p1;
    cout<<sum;
    return 0;
}
