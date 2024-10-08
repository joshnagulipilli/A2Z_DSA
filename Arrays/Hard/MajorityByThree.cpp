
#include<bits/stdc++.h>
using namespace std;

vector<int> brute(vector<int>& arr)    // o(n*n) + o(1)
{  
   int n=arr.size();
   vector<int>ans;
   for(int i=0;i<n;i++)
   {
    int c=0;
    if(ans.size()==0 ||  ans.back()!=arr[i] ){
    for(int j=0;j<n;j++)
    {
       if(arr[i]==arr[j]) c++;
    }
    }
    if(c>(n/3)) {
        ans.push_back(arr[i]);
    }
    if(ans.size()==2) break;    // since n/3 range means the number of elements are not more greater than two
   }
   return ans;
}

vector<int> better(vector<int>& arr)   //o(n) + o(n)
{
   int n=arr.size();
   vector<int>ans;
   map<int,int>mp;
   for(int i=0;i<n;i++)
   {
    mp[arr[i]]++;
    if(mp[arr[i]] > (n/3))           // mp[arr[i]] takes o(log n ) for unordered map it is o(1)
    {
        ans.push_back(arr[i]);
    }
   }
   return ans;
}


vector<int> optimal(vector<int>& arr)  //o(n)
{
    int n=arr.size();
    vector<int>ans;
    int el1=-1,el2=-1,c1=0,c2=0;
    for(int i=0;i<n;i++)
    {
        if(c1==0 && el2!=arr[i])
        {
            el1=arr[i];
            c1=1;
        }
        else if(c2==0 && el1!=arr[i])
        {
            el2=arr[i];
            c2=1;
        }
        else if(el1==arr[i]) c1++;
        else if(el2==arr[i]) c2++;
        else{
            c1--;
            c2--;
        }
    }
    //checking if the element el1 el2 are majority or not 
    c1=0,c2=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==el1) c1++;
        else if(arr[i]==el2) c2++;
    }
    if(c1> (n/3) ) ans.push_back(el1);
    if(c2> (n/3) ) ans.push_back(el2);
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
    // vector<int>sol=brute(arr);
    // for(int i=0;i<sol.size();i++)
    //    {
    //     cout<<sol[i]<<" ";
    //    }
    //    cout<<endl;
    // vector<int>ans= better(arr);
    // for(int i=0;i<ans.size();i++)
    // {
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    vector<int>res=optimal(arr);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}