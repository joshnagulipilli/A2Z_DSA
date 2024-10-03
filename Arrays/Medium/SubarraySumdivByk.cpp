#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>& arr,int k)
{
    int n=arr.size();
    unordered_map<int,int>mp;
    mp[0]=1;
    int sum=0;
    int cnt=0;
    int i=0;
    while(i<n)
    {
        sum+=arr[i];
        int rem=((sum%k)+k)%k;
        if(mp.find(rem)!=mp.end())
        {
            cnt+=mp[rem];
        }
        mp[rem]++;
        i++;
    }
    return cnt;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<brute(arr,k)<<endl;
    
}