#include<bits/stdc++.h>
using namespace std;

int binary(vector<int>& arr , int n ,int cows){
    int low = *min_element(arr.begin(),arr.end());
    int high = *max_element(arr.begin(),arr.end());
    
}


int main(){
    int n,cows;
    cin>>n>>cows;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<binary(arr,n,cows)<<endl;
}