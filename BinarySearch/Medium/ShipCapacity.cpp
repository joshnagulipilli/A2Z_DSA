#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>&arr , int n, int mid , int days){
    int cap = 0;
    int res = 0;
    for(auto it:arr){
        cap+=it;
        if(cap>mid){
            res +=1;
            cap = it;
        }
    }
    res++;
    return res;
}

int binary(vector<int>& arr, int n, int days)
{
    int low=*max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    int capacity=0;
    while(low<=high){
        int mid=(low+high)/2;
        int val = fun(arr,n,mid,days);
        if(val<=days){
            capacity = mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return capacity;
}

int main()
{
    int n,days;
    cin>>n>>days;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<binary(arr,n,days)<<endl;
}