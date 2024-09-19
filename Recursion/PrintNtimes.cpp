// 1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 .......N

#include<bits/stdc++.h>
using namespace std;

void fun(int n)
{
   if(n==1) 
   {
    cout<<1<<" ";
    return ;
   }
   fun(n-1);
   cout<<n<<" ";
   return ;
}

int main()
{
    int n;
    cin>>n;
    fun(n);
    return 0;
}