#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>& arr,int n ,int sum , int mid){
    int res=0;
    for(int i=0;i<n;i++)
    {
        res+= ceil((double)arr[i]/(double)mid);
    }
    if(res<=sum) return true;
    return false;

}

int binary(vector<int>& arr , int n ,int sum){     // o(log n) + o(1)
        int low=1;
        int high=*max_element(arr.begin(),arr.end());
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            int val = fun(arr,n,sum,mid);
            if(val==true){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<binary(arr,n,m)<<endl;
}