#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>& arr , int n)
{
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        if(i*i<=n){
            ans=i;
        }
        else break;
    }
    return ans;
}

int binary(vector<int>&arr , int n){     // o(log n) + o(1)
        int low=1,high=n-1;
        int ans=1;
        while(low<=high)
        {
            int mid =(low+high)/2;
            if(mid*mid <= n) {
                ans=mid;
                low=mid+1;
            }
            else if(mid*mid > n) high=mid-1;
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
    cout<<brute(arr,n)<<endl;
    cout<<binary(arr,n)<<endl;
}