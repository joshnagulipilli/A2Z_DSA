#include<bits/stdc++.h>
using namespace std;

//brute using two loops 

int brute(vector<int>& arr) //o(n)
{
  int cnt=0;
  int maxi=0;
  for(int i=0;i<arr.size();i++)
 {
    if(arr[i]==1)
    {
        cnt++;
    }
    else{
        maxi=max(maxi,cnt);
        cnt=0;
    }
 }
 return maxi;
}


int better(vector<int>& arr)
{
   
}
int optimal(vector<int>& arr)
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
    cout<<brute(arr)<<endl;
    // cout<<better(arr)<<endl;
    // cout<<optimal(arr)<<endl;
}
