#include<bits/stdc++.h>
using namespace std;

#define ll long long



long long fact(long long n)
    {
        if(n==1 ) return 1;
        return n*fact(n-1);
    }
    
vector<ll> solve(long long n)
{
    vector<ll>ans;
    long long res=1,i=2;
    while(res<=n)
        {
         ans.push_back(res);
          res=fact(i);
          i++;
        }
        return ans;
}

int main()
{
    long long n;
    cin>>n;
    vector<ll>v=solve(n);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}