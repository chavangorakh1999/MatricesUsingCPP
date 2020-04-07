//
//  main.cpp
//  SparseMatrix
//
//  Created by Gorakh Chavan on 07/04/20.
//  Copyright © 2020 Gorakh Chavan. All rights reserved.
//

#include <iostream>
using namespace std;

struct element
{
    int i;
    int j;
    int x;
};
struct SparseMatrix
{
    int m;
    int n;
    int num;
    struct element *e;
};
void CreateSparseMatrix(struct SparseMatrix *s)
{
    cout<<"Enter Dimensions";
    cin>>s->m>>s->n;
    cout<<"Enter number of non-zero elements";
    cin>>s->num;
    s->e=new element[s->num];
    cout<<"Enter all elements ";
    for(int i=0;i<s->num;i++)
    {
        cin>>s->e[i].i>>s->e[i].j>>s->e[i].x;
    }
    
    
}
void display(struct SparseMatrix s)
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
}
int main()
{
    struct SparseMatrix s;
    CreateSparseMatrix(&s);
    display(s);
    
    
    return 0;
}
