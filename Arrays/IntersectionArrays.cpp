#include<bits/stdc++.h>
using namespace std;

void brute(vector<int>& arr1,vector<int>& arr2)    // o(n*m  +  x)  + O(m)
{
   int n=arr1.size();
   int m=arr2.size();
   bool vis[m]={0};          // space o(m)
   vector<int>ans;
   for(int i=0;i<n;i++)         //o(n)  * 
   {                          //         ****  o(n*m)
    for(int j=0;j<m;j++)       //o(m)   *
    {
        if(arr1[i]==arr2[j] && vis[j]==0)
        {
             vis[j]=1;
             ans.push_back(arr1[i]);
             break;
        }
        else if(arr1[i]<arr2[j])
        {
            break;
        }
    }
   }
   for(int i=0;i<ans.size();i++)    //o(ans.size())
   {
    cout<<ans[i]<<" ";
   }
}
int better(vector<int>& arr1,vector<int>& arr2)
{

}

//arrays should be sorted if not mentioned as sorted
void optimal(vector<int>& arr1,vector<int>& arr2)       //  o(n+m) + o(n+m)
{
    int n=arr1.size();
    int m=arr2.size();
    int i=0,j=0;
    vector<int>ans;
    while(i<n && j<m)
    {
        if(arr1[i]==arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;j++;
        }
        else if(arr1[i]<arr2[j])
        {
            i++;
        }
        else if(arr2[j]<arr1[i])
        {
            j++;
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>arr1(n),arr2(m);
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    //  brute(arr1,arr2);
    //  better(arr1,arr2);
    optimal(arr1,arr2);
    
}