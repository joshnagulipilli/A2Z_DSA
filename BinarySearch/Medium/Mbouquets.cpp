#include<bits/stdc++.h>
using namespace std;

bool fun(vector<int>&arr , int n,int mid , int k,int m){
   int cnt=0;
   int res=0;
   for(int i=0;i<n;i++){
    if(arr[i]<=mid) cnt++;
    else 
    {
        res += cnt/k;
        cnt=0;
    }
   }
   res +=(cnt/k);
   if(res>=m) return true;
   return false;
}

int binary(vector<int>& arr , int n , int m,int k){     // o(log n) + o(1)
        int low=*min_element(arr.begin(),arr.end());
        int high=*max_element(arr.begin(),arr.end());
        if(m*k > n) return -1;
        int ans=INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            int val = fun(arr,n,mid,k,m);
            if(val == true) {
               ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<binary(arr,n,m,k)<<endl;
}