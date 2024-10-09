#include<bits/stdc++.h>
using namespace std;


int brute(vector<int>& arr)   //o(n*n) + o(1)
{
   int n=arr.size();
   int cnt=0;
   for(int i=0;i<n-1;i++)
   {
    for(int j=i+1;j<n;j++)
    {
        if(arr[j]<arr[i]) cnt++;
    }
   }
   return cnt;
}

int better(vector<int>& arr)   
{
 return 0;
}

//concept of merge sort

int merge(vector<int>& arr,int low,int mid,int high)
{
    vector<int>temp;
    int left=low;
    int right=mid+1;
    int cnt=0;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else{
            cnt+=(mid-left+1);
            temp.push_back(arr[right]);
            right++;
        }
        while(left<=mid) 
        {
            temp.push_back(arr[left]);
            left++;
        }
         while(right<=high) 
        {
            temp.push_back(arr[right]);
            right++;
        }

    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
    return cnt;
}

int mergeSort(vector<int>& arr, int low,int high) 
{
    int cnt=0;
    if(low>=high) return cnt;
    int mid=(low+high)/2;
    cnt+=mergeSort(arr,low,mid);
    cnt+=mergeSort(arr,mid + 1,high);
    cnt+=merge(arr,low,mid,high);
    return cnt;
}

int optimal(vector<int>& arr)   // o(nlog n) + o(n)
{
    return mergeSort(arr,0,arr.size()-1);
    
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
    return 0;
}
