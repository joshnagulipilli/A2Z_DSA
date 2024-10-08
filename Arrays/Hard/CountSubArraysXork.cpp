#include<bits/stdc++.h>
using namespace std;


int brute(vector<int>& arr,int k)   // o(n*n*n) + o(1)
{
  int n=arr.size();
  int cnt=0;
  for(int i=0;i<n;i++)
  {
    for(int j=i;j<n;j++)
    {
        int x=0;
        for(int p=i;p<=j;p++)
        {
            x=x^arr[p];

        }
        if(x==k) cnt++;
    }
  }
  return cnt;
}




int better(vector<int>& arr,int k)     //o(n*n) + o(1)
{
   int n=arr.size();
  int cnt=0;
  for(int i=0;i<n;i++)
  {
     int x=0;
    for(int j=i;j<n;j++)
    {
       
        x=x^arr[j];
        if(x==k) cnt++;
    }
  }
  return cnt;
}

//using hashing  works for both negatives and positives 
int optimal(vector<int>& arr,int k)   // o(n ) or o(NlogN if map) + o(n)
{
    unordered_map<int,int>mp;
    int x=0;
    mp[x]++;
    int n=arr.size();
    int cnt=0;

    for(int i=0;i<n;i++)
    {
        x=x^arr[i];
        int rem=x^k;
        cnt+=mp[rem];
        mp[x]++;
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
    cout<<better(arr,k)<<endl;
    cout<<optimal(arr,k)<<endl;
}
