#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int sum=0,maxi=INT_MIN;
    int s=0,start=-1,end=-1;
    for(int i=0;i<n;i++)
    {
        if(sum==0) 
        {
           s=i;
        }
        sum+=arr[i];
        if(sum>maxi)
        {
            maxi=sum;
            start=s;
            end=i;
        }
        if(sum<0) sum=0;
    }
    for(int i=start;i<=end;i++)
    {
        cout<<arr[i]<<" ";
    }
}