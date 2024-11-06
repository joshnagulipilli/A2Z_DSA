#include<bits/stdc++.h>
using namespace std;

   int firstOccurence(vector<int>& arr,int target,int low, int high){
       int first=-1;
       while(low<=high)
       {
           int mid=(low+high)/2;
           if(arr[mid]==target)
           {
               first=mid;
               high=mid-1;
           }
           else if(arr[mid]< target) low=mid+1;
           else high=mid-1;
       }
       return first;
   }
   
    int lastOccurence(vector<int>& arr,int target,int low, int high){
       int last=-1;
       while(low<=high)
       {
           int mid=(low+high)/2;
           if(arr[mid]==target)
           {
               last=mid;
               low=mid+1;
           }
           else if(arr[mid] < target) low=mid+1;
           else high=mid-1;
       }
       return last;
    }
  
  int main()
  {
    int n,key;
    cin>>n>>key;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int first=firstOccurence(arr,key,0,n-1);
    int last=lastOccurence(arr,key,0,n-1);
    if(first==-1)
    cout<<"Element is not present in array"<<endl;
    else
    cout<<"First Occurence of "<<key<<" is at index "<<first<<endl;
    cout<<"Last Occurence of "<<key<<" is at index "<<last<<endl;
    return 0;
  }