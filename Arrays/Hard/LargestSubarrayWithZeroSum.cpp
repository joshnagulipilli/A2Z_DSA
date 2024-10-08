#include<bits/stdc++.h>
using namespace std;


int brute(vector<int>& arr)   // o(n*n*n) + o(1)
{
   int maxi=0;
   int n=arr.size();
   for(int i=0;i<n;i++)
   {
    for(int j=i;j<n;j++)
    {
        int sum=0;
        for(int k=i;k<=j;k++)
        {
            sum+=arr[k];
        }
        if(sum==0)
        {
            maxi=max(maxi,j-i+1);
        }
    }
   }
   return maxi;
}




int better(vector<int>& arr)     //o(n*n) + o(1)
{
   int maxi=0;
   int n=arr.size();
   for(int i=0;i<n;i++)
   {
    int sum=0;
    for(int j=i;j<n;j++)
    {
         sum+=arr[j];
        if(sum==0)
        {
            maxi=max(maxi,j-i+1);
        }
    }
   }
   return maxi;
}

//using hashing  works for both negatives and positives 
int optimal(vector<int>& arr)   //o(n + log n) + o(n)
{
    int n=arr.size();
    unordered_map<int,int> mp;
    int maxi=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
        {
            maxi=max(maxi,i+1);
        }
        if(mp.find(sum)!=mp.end())
        {
            maxi=max(maxi,i-mp[sum]);

        }
        else if(mp.find(sum)==mp.end())
        {
            mp[sum]=i;  // 2 0 0 0 3 -> should return 4 , since sum 2 + 0 + 0 + 0 = 2 stores in map with index 3 gives wrong answer . so if we have zeroes and already sum exists then no need to push in map
        }
    }
   return maxi;
}




int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
   
    cout<<brute(arr)<<endl;
    cout<<better(arr)<<endl;
    cout<<optimal(arr)<<endl;
}
