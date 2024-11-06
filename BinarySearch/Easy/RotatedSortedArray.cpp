#include<bits/stdc++.h>
using namespace std;

// 7 8 9 1  2 3 4 5 6   

int unique(vector<int>& arr, int k , int low , int high){
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid] == k) return mid;
        // sorted left part
        if(arr[low] <= arr[mid])
        {
            if(arr[low]<=k && arr[mid]>=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(arr[mid]<=k && arr[high]>=k)
            {
                //element is here
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}


int duplicate(vector<int>& arr, int k , int low , int high){
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid] == k) return mid;
        // sorted left part
        if(arr[low]==arr[mid] && arr[mid]==arr[low])
        {
            low++;
            high--;
            continue;
        }
        if(arr[low] <= arr[mid])
        {
            if(arr[low]<=k && arr[mid]>=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(arr[mid]<=k && arr[high]>=k)
            {
                //element is here
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
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
    cout<<unique(arr,key,0,n-1)<<endl;
    cout<<duplicate(arr,key,0,n-1)<<endl;
  }