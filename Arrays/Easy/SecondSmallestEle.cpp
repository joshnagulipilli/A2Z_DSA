#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>& arr )    //o(nlogn + n-1) + o(1)
{  
    sort(arr.begin(),arr.end());
    int small=arr[0];
    int sec=INT_MAX;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]!=small)
        {
            sec=arr[i];
            break;
        }
    }
    return sec;
}
int better(vector<int>& arr)    //o(n + n)  + o(1)
{
   int small=INT_MAX;
   int sec=INT_MAX;
   for(int i=0;i<arr.size();i++)
   {
    if(small>arr[i])
    {
        small=arr[i];
    }
   }
   for(int i=0;i<arr.size();i++)
   {
    if(small!=arr[i] && sec>arr[i])
    {
       sec=arr[i];
    }
   }
   return sec;
}
int optimal(vector<int>& arr)
{
    int small=arr[0];
    int sec=INT_MAX;
    for(int i=1;i<arr.size();i++)
    {
        if(small>arr[i])
        {
            sec=small;
            small=arr[i];
        }
        else if(arr[i]!=small && arr[i]<sec){  // 5 1 2 3 9 if small is 1 found then it does'nt enter if . so for //sec updation we have to check this condition
            sec=arr[i];
        }
    }
    return sec;
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