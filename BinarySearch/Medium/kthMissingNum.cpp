#include<bits/stdc++.h>
using namespace std;


int linear(vector<int>&arr , int k){     // o(log n) + o(1)
    int cnt=k;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<cnt) cnt++;
    }
    return cnt;
}

int recursive(vector<int>&arr , int k , int low , int high)  // o(log n) + o(1)
{
    while(low<=high){
        int mid=(low+high)/2;
        int missing = arr[mid]-(mid+1);
        int p;
        if(missing < k)
        {
            low=mid+1;
        }
        else high=mid-1;
    }
   // since in case of k=3 and [4,7,9] high points to -1 , so returning high should be avoided
   // arr[high] + (k - missing)
   // arr[high] + k - (arr[high]-high-1);
   //high+1+k; or (low+k);
   return low+k;
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
    cout<<linear(arr,k)<<endl;
    //cout<<recursive(arr,k,0,arr.size()-1)<<endl;
}