
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>& arr)   //o(n*n) + o(1)
{ 
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]==arr[i]) cnt++;
        }
        if(cnt>=(n/2)) return arr[i];
    }
    return 0;
}


int better(vector<int>& arr)     //o(nlogn) + o(n)
{
     int n=arr.size();
     unordered_map<int,int>mp;
     for(int i=0;i<n;i++)
     {
        mp[arr[i]]++;
     }
     for(auto it:mp)
     {
        if(it.second>=(n/2)) return it.first;
     }
     return 0;
}


//Moore Voting algorithm
int optimal(vector<int>& arr)        // o(n + n) + o(1)
{
   int n=arr.size();
  // int curr;    -->   v[i]              // to check previous counted el is curr 
   int el;                       // el represents most occurence till index
   int cnt=0;                    // cnt will cancels when el and curr are diff
   for(int i=0;i<n;i++)
   {
    if(cnt==0)
    {
        el=arr[i];
        cnt=1;
    }
    else if(el == arr[i]) cnt++; // if curr is el 
    else cnt--; 
   }


   //if element is majority or not , since in question it may or may not there any majority element
   int c=0;
   for(int i=0;i<arr.size();i++)
   {
    if(arr[i]==el) c++;
   }
   if(c >=(n/2)) return el;
   return 0;
    
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