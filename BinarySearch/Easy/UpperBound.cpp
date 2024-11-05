#include<bits/stdc++.h>
using namespace std;


int iterative(vector<int>&arr , int x){     // o(log n) + o(1)
    int n=arr.size();
    int low=0,high=n-1;
    int ans=arr[high];
    while(low<=high)
    {
        int mid =(low+high)/2;
        if(arr[mid] > x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
           }
    }
    return ans;
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
    cout<<iterative(arr,key)<<endl;
}