
#include<bits/stdc++.h>
using namespace std;


//1.generate all seq 
//2.linear search current arr
//3 . return next arr to curr
//done by recursion

int brute(vector<int>& arr)   //
{ 
    
}


void better(vector<int>& arr)    //o*(n)
{
       next_permutation(arr.begin(),arr.end());

}


void optimal(vector<int>& arr)   //o(n+n+n-x) + o(1)  
{
  int n=arr.size();
  int ind=-1;
  for(int i=n-2;i>=0;i--)        //o(n) in worst case
  {
    if(arr[i]<arr[i+1])
    {
        ind=i;
        break;
    }
  }
  if(ind==-1) 
  {
    reverse(arr.begin(),arr.end());   //o(n)
    return ;
  }
  for(int i=n-1;i>=ind;i--)
  {
    if(arr[i]>arr[ind])
    {
        swap(arr[ind],arr[i]);
        break;
    }
  }
  reverse(arr.begin()+ind+1,arr.end());   //o(n-x)
  return ;

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
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    
}