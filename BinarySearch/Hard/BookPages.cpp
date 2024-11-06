#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>&arr , int mid){
    int stud=1,pages=0;
    for(auto it:arr){
        if(pages + it <= mid){
            pages+=it;
        }
        else{
            stud++;
            pages=it;
        }
    }
    return stud;
}

int binary(vector<int>& arr , int n ,int stud){
    if(stud >n) return -1;  
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low <= high){
        int mid = (low + high)/2;
        int val = fun(arr,mid);
        if(val > stud ){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<binary(arr,n,m)<<endl;
}