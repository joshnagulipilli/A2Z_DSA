#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>& arr)          // o(nlogn + n-1)   + o(1)  in worst case it is n-1
{
     sort(arr.begin(),arr.end());
     int large=arr[arr.size()-1];
     int sec=-1;
     for(int i=arr.size()-2;i>=0;i--)
     {
        if(arr[i]!=large)
        {
            sec=arr[i];
            break;
        }
     }
     return sec;
}
int better(vector<int>& arr)      //o(n+n)   + o(1)
{
   int large=INT_MIN;
   for(int i=0;i<arr.size();i++)
   {
    if(arr[i]>large)
    {
        large=arr[i];
    }
   }
   int sec=INT_MIN;
   for(int i=0;i<arr.size();i++)
   {
    if(arr[i]!=large && arr[i]>sec)
    {
        sec=arr[i];
    }
   }
   return sec;
}
int optimal(vector<int>& arr)  // o(n) + o(1)
{
    int maxi=arr[0];
    int sec=INT_MIN;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]>maxi)
        {
            sec=maxi;
            maxi=arr[i];
        }
        else if(arr[i]!=maxi && arr[i]>sec){  // 72 71 61 42 31 - if 72 is max then it wont update for further
            sec=arr[i];
         }
    }
    return sec;
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
    // cout<<brute(arr)<<endl;
    // cout<<better(arr)<<endl;
    cout<<optimal(arr)<<endl;
}