#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=2;i*i<=n;i++)       // for(int i=2;i<=sqrt(n);i++) here it always calculate sqrt(n) to check whether i<=sqrt(n) time taken is o(sqrt(n) +log(n));
    {
        if(n%i==0)
        {
           v.push_back(i);
           if((n/i) != i) 
           {
            v.push_back(n/i);
           }
        }
    }
   for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
}