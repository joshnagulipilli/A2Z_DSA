
#include<bits/stdc++.h>
using namespace std;


//1.generate all seq 
//2.linear search current arr
//3 . return next arr to curr
//done by recursion

int brute(vector<int>& arr)   //
{ 
    
}


void better(vector<int>& arr)    
{
       next_permutation(arr.begin(),arr.end());

}


int optimal(vector<int>& arr)   //o(n) + o(1)  
{
  
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
    // cout<<brute(arr)<<endl;
    better(arr);
    // cout<<optimal(arr)<<endl;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    
}