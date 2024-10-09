
#include<bits/stdc++.h>
using namespace std;

void brute(vector<int>& arr,vector<int>& arr2)     //o((n+m)+ (n+m)) +    o(n+m)
{  
   int n=arr.size();
   int m=arr2.size();
   vector<int>ans;
   int i=0,j=0;
   while(i<n && j<m)
   {
    if(arr[i]<arr2[j])
    {
        ans.push_back(arr[i]);
        i++;
    }
    else {
        ans.push_back(arr2[j]);
        j++;
    }
   }
   while(i<n) {
     ans.push_back(arr[i]);
        i++;
   }
   while(j<m) {
     ans.push_back(arr[j]);
        j++;
   }
   for(int i=0;i<n;i++)
   {
    arr[i]=ans[i];
   }
   for(int i=n;i<n+m;i++)          // for off-by-one error . 
   {                                //for(int i=0;i<m;i++) arr2[i]=arr[i+n];
    arr2[i-n]=ans[i];
   }
}


void optimal1(vector<int>& arr,vector<int>& arr2)   // o(min(n,m) + nlogn + mlogm)    + o(1) 
{
   int n=arr.size();
   int m=arr2.size();
   int i=n-1,j=0;
   while(i<n && j<m)           // it breaks if arr1 is min element to arr2 
   {
    if(arr[i]>arr2[j])
    {
        swap(arr[i],arr2[j]);
        i--;
        j++;
    }
    else break;
   }
   sort(arr.begin(),arr.end());
   sort(arr2.begin(),arr2.end());
}

//using gap method 
// which os from shell sort algorithm

void swapGreater(vector<int>&arr1,vector<int>&arr2,int ind1,int ind2)
{
    if(arr1[ind1] > arr2[ind2])
    swap(arr1[ind1],arr2[ind2]);
}

void optimal2(vector<int>& arr1,vector<int>& arr2)  
{
    int n=arr1.size(),m=arr2.size();
    int len=(n+m);
    int gap=(len/2)+(len%2);    
    while(gap>0)
    {
    int left=0;
    int right=left+gap;
    while(right<len)
    {
        //arr1 and arr2
        if(left<n && right>=n)
        {
            swapGreater(arr1,arr2,left,right-n);
        }
        //arr1 and arr1
        else if(left<n && right < n)
        {
            swapGreater(arr1,arr1,left,right);
        }
        //arr2 and arr2
        else if(left>=n && right>=n)
        {
            swapGreater(arr2,arr2,left-n,right-n);
        }
        left++;
        right++;
    }
    if(gap==1) break;
    else gap=(gap/2)+(gap%2);
}
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>arr(n),arr2(m);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<m;i++) cin>>arr2[i];
    // brute(arr,arr2);
    // optimal1(arr,arr2);
    optimal2(arr,arr2);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    for(int i=0;i<m;i++) cout<<arr2[i]<<" ";
    
}
