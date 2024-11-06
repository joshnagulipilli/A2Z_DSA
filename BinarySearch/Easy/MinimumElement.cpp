#include<bits/stdc++.h>
using namespace std;

// 7 8 9 1  2 3 4 5 6

int fun(vector<int>& arr, int low, int high){
    int ans=INT_MAX;
    while(low<=high)
    {
        int mid= (low+high)/2;
        if(arr[low]<=arr[mid])
        {
            ans=min(ans,arr[low]);
            low=mid+1;
        }
        else if(arr[mid]<=arr[high])
        {
            ans=min(ans,arr[mid]);
            high=mid-1;
        }
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
    cout<<fun(arr,0,n-1)<<endl;
  }