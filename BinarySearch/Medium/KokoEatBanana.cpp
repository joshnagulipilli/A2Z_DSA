#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>&arr , int hr)
{
   int req = 0;
   for(int i=0;i<arr.size();i++)
   {
    req += ceil((double)arr[i]/(double)hr);
   }
   return req;
}

int binary(vector<int>& arr , int n , int time){     // o(log n) + o(1)
        int low = 1,ans=INT_MAX;
        int high = *max_element(arr.begin(),arr.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(fun(arr,mid)<= time) 
            {
                ans=mid;
                high=mid-1;
            }
            else  low=mid+1;
        }
        return ans;
}

int main()
{
    int n,time;
    cin>>n>>time;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<binary(arr,n,time)<<endl;
}