
#include<bits/stdc++.h>
using namespace std;


//return indexes

pair<int,int> brute(vector<int>& arr,int d)    //o(n*n) + o(1)
{
   int n=arr.size();
   for(int i=0;i<n;i++)
   {
    for(int j=i+1;j<n;j++)
    {
        if(arr[i]+arr[j]==d)
        {
           return {i,j};
        }
    }
   }
   return {-1,-1};

}

//using hashing

pair<int,int> better(vector<int>& arr,int d)   // o(nlogn) + o(n)
{
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++)
    {
        int t=d-arr[i];
        if(mp.find(t)!=mp.end())
        {
            return {i,mp[t]};
        }
        else{
            mp[arr[i]]=i;
        }
    }
    return {-1,-1};
}
bool optimal(vector<int>& arr,int d)       
{
    sort(arr.begin(),arr.end());
    int left=0,right=arr.size()-1;
    int sum=0;
    while(left<=right)
    {
        if(arr[left]+arr[right] == d) return true;
        else if (arr[left]+arr[right] > d) right--;
        else left++;
    }
    return false;
    
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
    // pair<int,int> p = brute(arr,k);
    // pair<int,int>p=better(arr,k);
   // cout<<p.first<<" "<<p.second<<endl;
    cout<<optimal(arr,k)<<endl;
   
}