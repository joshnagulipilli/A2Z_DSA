// GFG GFG GFG GFG GFG

#include<bits/stdc++.h>
using namespace std;

void fun(int n)
{
   if(n==1) 
   {
    cout<<"DSA"<<" ";
    return ;
   }
   fun(n-1);
   cout<<"DSA"<<" ";
   return ;
}

int main()
{
    int n;
    cin>>n;
    fun(n);
    return 0;
}