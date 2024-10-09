#include<bits/stdc++.h>
using namespace std;


vector<pair<int,int>> brute(vector<pair<int,int>>& arr)   //o(nlogn + 2N) + o(n)
{
     vector<pair<int,int>>ans;                         // at worst case o(n)
     sort(arr.begin(),arr.end());                       //o(nlogn)
     int n=arr.size();
     for(int i=0;i<n;i++)                               //o(n)
     {
        int start=arr[i].first;
        int end=arr[i].second;
        if(!ans.empty() && end<=ans.back().second)
        {
           continue;
        }
        for(int j=i+1;j<n;j++)                   //o(n-x) not moves end since overlapping may not occurs in all pairs
        {
            if(arr[j].first < end)
            {
                end=max(end,arr[j].second);
            }
            else break;
        }
        ans.push_back({start,end});
     }
     return ans;
}

vector<pair<int,int>> optimal(vector<pair<int,int>>& arr) //o(nlogn + n) + o(n)
{
   vector<pair<int,int>>ans;              //space o(n)
   sort(arr.begin(),arr.end());          //o(nlogn)
   int n=arr.size();
   for(int i=0;i<n;i++)             //o(n)
   {
    if(ans.empty() || arr[i].first>ans.back().second)
    {
         ans.push_back(arr[i]);
    }
    else{
        ans.back().second=max(ans.back().second,arr[i].second);
    }
   }
   return ans;
}




int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    
   
    // vector<pair<int,int>>ans=brute(arr);
    vector<pair<int,int>>ans=optimal(arr);
    for(auto i:ans)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
}
