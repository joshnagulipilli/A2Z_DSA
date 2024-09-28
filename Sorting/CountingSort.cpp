#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        maxi=max(v[i],maxi);
    }
    vector<int>cnt(maxi+1,0);
    for(int i=0;i<n;i++)
    {
        cnt[v[i]]++;
    }
    for(int i=1;i<=cnt.size();i++)
    {
        cnt[i]=cnt[i]+cnt[i-1];
    }
    vector<int>output(n);
    for(int i=n-1;i>=0;i--)
    {
        output[cnt[v[i]]-1] = v[i];
        cnt[v[i]]--;
    }
    for(int i=0;i<n;i++)
    {
        cout<<output[i]<<" ";
    }

}