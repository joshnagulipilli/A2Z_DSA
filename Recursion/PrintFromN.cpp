// 1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 .......N
//by backtracking
#include<bits/stdc++.h>
using namespace std;

void fun(int i,int n)
{
   if(i>n) 
   {
    return ;
   }
   
   fun(i+1,n);
   cout<<i<<" ";
   return ;
}

int main()
{
    int n;
    cin>>n;
    fun(1,n);
    return 0;
}