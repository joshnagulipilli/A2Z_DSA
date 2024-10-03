
#include<bits/stdc++.h>
using namespace std;

void brute(vector<int>& arr)    //o(n*n) + o(n)
{ 
   int n=arr.size();
   vector<int>ans;
   for(int i=0;i<n-1;i++)
   {
    int c=0;
    for(int j=i+1;j<n;j++)
    {
       if(arr[j]>arr[i])
       {
        c++;
        break;
       }
    }
    if(!c) ans.push_back(arr[i]);

   }

   ans.push_back(arr[n-1]);
   for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}


void better(vector<int>& arr)    {
   
}


void optimal(vector<int>& arr)   //o(n+n) + o(n)
{
    int n=arr.size();
    int maxi=arr[n-1];
    vector<int>ans;
    ans.push_back(maxi);
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>maxi)
        {
            maxi=arr[i];
            ans.push_back(maxi);
        }
    }
    for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
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
    // brute(arr);
    // better(arr);
    optimal(arr);
    // for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

}