#include<bits/stdc++.h>
using namespace std;


void linear(vector<int>&arr , int k){     // o(log n) + o(1)
    int n=arr.size();
    int first =-1 , last=-1;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==k)
        {
            if(first==-1) first=i;
            last=i;
        }
    }
    cout<<first<<" "<<last<<endl;
}

void binary(vector<int>&arr , int k , int low , int high)  // o(log n) + o(1)
{
   //finding lower and upper bound ;
  // if(lb == n || arr[lb -1] !=k) // if lb of k is n which is out of range . or targeting element is not present but points to greater element then {-1,-1};

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
    linear(arr,key);
   binary(arr,key,0,arr.size()-1);
}