#include<bits/stdc++.h>
using namespace std;

int onePeak(vector<int>&arr , int k){     // o(log n) + o(1)
    int n=arr.size();
    if(n==1) return 0;
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;
    int low=1,high=n-2;
    while(low<=high)
    {
        int mid =(low+high)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) return mid;
        else if(arr[mid]<arr[mid+1]) low=mid+1;
        else if(arr[mid]<arr[mid-1]) high=mid-1;
    }
    return -1;
}
int manyPeak(vector<int>&arr , int k){     // o(log n) + o(1)
    int n=arr.size();
    if(n==1) return 0;
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;
    int low=1,high=n-2;
    while(low<=high)
    {
        int mid =(low+high)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) return mid;
        else if(arr[mid]<arr[mid+1]) low=mid+1;
        else if(arr[mid]<arr[mid-1]) high=mid-1;
        else high=mid-1;
    }
    return -1;
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
    cout<<onePeak(arr,key)<<endl;
   cout<<manyPeak(arr,key)<<endl;
   
}