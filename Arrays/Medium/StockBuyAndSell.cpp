
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>& arr)   //o(n*n) + o(1)
{ 
    int n = arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[i])
               maxi=max(maxi,arr[j]-arr[i]);
        }
    }
    return maxi;
}


int better(vector<int>& arr)    
{
     return 0;
}


int optimal(vector<int>& arr)   //o(n) + o(1)  
{
   int n = arr.size();
    int maxi=INT_MIN;
    int mini=arr[0];
    for(int i=0;i<n;i++)
    {
        mini=min(mini,arr[i]);
        maxi=max(maxi,arr[i]-mini);
    }
    return maxi;
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
    cout<<optimal(arr)<<endl;
}