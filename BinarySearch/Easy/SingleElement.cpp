#include<bits/stdc++.h>
using namespace std;

// 
//(even , odd) ->  element is in left half
//(odd,even) ->element is in right half
int fun(vector<int>& arr, int low, int high){
    low++;
    high--;
    int n=arr.size();
    if(n==1) return arr[0];
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2])  return arr[n-1];
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];
        if(mid%2 ==1 && arr[mid]==arr[mid-1] || (
            mid%2==0 && arr[mid]==arr[mid+1])) low=mid+1;
        else high= mid-1;
    }
    return -1;
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
    cout<<fun(arr,0,n-1)<<endl;
  }