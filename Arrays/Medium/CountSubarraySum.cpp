
#include<bits/stdc++.h>
using namespace std;


int brute(vector<int>& arr,int target)    //o(n*n*n) + o(1)
{  
    int n=arr.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum=0;
            for(int k=i;k<=j;k++)
            {
                sum+=arr[k];
            }
            if(sum==target) ans++;
        }
    }
    return ans;
}


int better(vector<int>& arr,int target)    //o(n*n) + o(1)
{
   int n=arr.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            if(sum==target) ans++;
        }
    }
    return ans;
}


int optimal(vector<int>& arr,int target)  //o(n) + o(n)
{
    int n=arr.size();
    int sum=0;
    int c=0;
    unordered_map<int,int>mp;
    mp[0]=1;
    int i=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        int rem=sum-target;
        c+=mp[rem];
        mp[sum]+=1;
    }
    return c;
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
    cout<<better(arr,k)<<endl;
    cout<<optimal(arr,k)<<endl;
    return 0;
}