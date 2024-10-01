#include<bits/stdc++.h>
using namespace std;


int brute(vector<int>& arr) // o(n*n) + o(1)
{
   int n=arr.size();
   for(int i=0;i<n;i++)
   {
    int c=0;
    for(int j=0;j<n;j++)
    {
        if(arr[j]==arr[i]) c++;
    }
    if(c==1) return arr[i];
   }
   return 0;
}


//using hashing

int better(vector<int>& arr) //o(nlog n) + o(n/2 + 1)
{
    map<int,int>mp;
    for(int i=0;i<arr.size();i++)
    {
        mp[arr[i]]++;
    }
    int miss=-1;
    for(auto it:mp)
    {
        if(it.second==1) miss=it.first;
    }
    return miss;
}


int optimal(vector<int>& arr) //o(n) + o(1)
{
    int n=arr.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans^=arr[i];
    }
    return ans;

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
