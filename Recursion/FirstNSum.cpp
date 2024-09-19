// 1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 .......N
//using parameterized 

#include<bits/stdc++.h>
using namespace std;

void fun(int i,int sum,int n)                      
{
   if(i==0)                     //functional 
   {
    cout<<sum<<endl;
    return ;
   }
   fun(i-1,sum+i,n);
   return ;
}

//functional 
int fun2(int n)
{
   if(n==0)
   {
      return 0;
   } 
   return n + fun2(n-1);
}

int main()
{
   int n;
   cin>>n;
   fun(n,0,n);
   cout<<fun2(n)<<endl;

}


