
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>& arr)   //o(n*n*n) + o(1)
{ 
    int n = arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
              int sum=0;
              for(int k=i;k<=j;k++){
                    sum+=arr[k];
              }
              maxi=max(maxi,sum);
        }
    }
    return maxi;
}


int better(vector<int>& arr)     //o(n*n) + o(1)
{
     int n = arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
         int sum=0;
        for(int j=i;j<n;j++)
        {
                    sum+=arr[j];
              maxi=max(maxi,sum);
        }
    }
    return maxi;
}


int optimal(vector<int>& arr)     
{
   int sum=0;
   int maxi=INT_MIN;
   for(int i=0;i<arr.size();i++)
   {
    sum+=arr[i];
    maxi=max(sum,maxi);
    if(sum<0) sum=0;
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