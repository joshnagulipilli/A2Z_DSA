#include<bits/stdc++.h>
using namespace std;


int iterative(vector<int>&arr , int k){     // o(log n) + o(1)
    int n=arr.size();
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid =(low+high)/2;
        if(arr[mid] == k) return mid;
        else if(k > arr[mid]) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int recursive(vector<int>&arr , int k , int low , int high)  // o(log n) + o(1)
{
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(arr[mid]==k) return mid;
    else if(arr[mid]>k) return recursive(arr,k,low,mid-1);
    return recursive(arr,k,mid+1,high);
}

int main()
{
    int n,key;
    cin>>n>>key;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //cout<<iterative(arr,key)<<endl;
    cout<<recursive(arr,key,0,arr.size()-1)<<endl;
}