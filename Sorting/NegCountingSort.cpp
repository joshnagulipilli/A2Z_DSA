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

    int maxi=*max_element(v.begin(),v.end());
    int mini=*min_element(v.begin(),v.end());
    int m=maxi-mini+1;
    vector<int>cnt(m,0);
    vector<int>output(n);
    for(int i=0;i<n;i++)
    {
        cnt[v[i]-mini]++;
    }
    for(int i=1;i<cnt.size();i++)
    {
        cnt[i]+=cnt[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        output[cnt[v[i]-mini]-1]=v[i];
        cnt[v[i]-mini]--;
    }




    for(int i=0;i<n;i++)
    {
        cout<<output[i]<<" ";
    }
    return 0;
}