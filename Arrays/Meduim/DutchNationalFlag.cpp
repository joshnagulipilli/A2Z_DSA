
#include<bits/stdc++.h>
using namespace std;

//by sorting

void brute(vector<int>& arr)   // o(nlogn) + o(1)
{
    sort(arr.begin(),arr.end());
}

// by counting
void better(vector<int>& arr)    //o(n+n)+o(1)
{
    int a=0,b=0,c=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==0) a++;
        else if(arr[i]==1) b++;
        else c++;
    }
    for(int i=0;i<arr.size();i++)
    {
        if(a!=0)
        {
            arr[i]=0;
            a--;
        }
        else if(b!=0)
        {
            arr[i]=1;
            b--;
        }
        else {
            arr[i]=2;
        }
    }
}

//dutch national flag algorithm

void optimal(vector<int>& arr)        // o(n) + o(1)
{
   int n=arr.size();
   int low=0,mid=0,high=n-1;
   while(mid<=high)
   {
        if(arr[mid]==1) mid++;
        else if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else 
        {
            swap(arr[high],arr[mid]);
            high--;
        }
   }
    
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