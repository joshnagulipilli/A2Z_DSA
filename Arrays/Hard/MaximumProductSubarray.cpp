#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>& arr)   //o(n*n*n) + o(1)
{
    int n=arr.size();
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int prod=1;
            for(int k=i;k<=j;k++)
            {
                prod=prod*arr[k];
            }
            ans=max(ans,prod);
        }
    }
    return ans;
}
int better(vector<int>& arr)  //o(n*n) + o(1)
{
    int n=arr.size();
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int prod=1;
        for(int j=i;j<n;j++)
        {
            prod=prod*arr[j];
            ans=max(ans,prod);
        }
    }
    return ans;
}
//not an intutive so never tell this to interviewer
int kadane(vector<int>& arr)
{
return 0;
}
int optimal(vector<int>& arr) //o(n)
{
    int n=arr.size();
    int ans=INT_MIN;
    int prefix=1,suffix=1;
    for(int i=0;i<n;i++)
    {
        if(prefix==0) prefix=1;
        if(suffix==0) suffix=1;
        prefix=prefix*arr[i];
        suffix=suffix*arr[n-1-i];
        ans=max(ans,max(prefix,suffix));
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
    cout<<brute(arr)<<endl;
    cout<<better(arr)<<endl;
     cout<<kadane(arr)<<endl;
    cout<<optimal(arr)<<endl;
}