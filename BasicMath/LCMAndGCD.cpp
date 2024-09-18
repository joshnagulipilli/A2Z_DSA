#include<bits/stdc++.h>
using namespace std;
long long fun2(long long a,long long b)
  {
      if(a==0) return b;
      if(b==0) return a;
      if(a>b) return fun2(a%b,b);
      return fun2(b%a,a);
  }
  
  
   long long fun1(long long a,long long b)
   {
    return (a*b)/fun2(a,b);
   }
int main()
{
    long long x,y;
    cin>>x>>y;
    long long lcm=fun1(x,y);
    cout<<lcm<<" ";
    long long gcd=fun2(x,y);
    cout<<gcd;
    
}