#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>& arr)      //o(nlogn)  + o(1)
{
   sort(arr.begin(),arr.end());
   return arr[arr.size()-1];
}
int better(vector<int>& arr)
{
   return 0;
}
int optimal(vector<int>& arr)  //o(n) + o(1)
{
   int maxi=INT_MIN;
   for(int i=0;i<arr.size();i++)
   {
    if(maxi<arr[i])
    {
        maxi=arr[i];
    }
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