
#include<bits/stdc++.h>
using namespace std;

void brute(vector<int>& arr)   //o(n + (n/2)) + o(n)
{ 
    int n = arr.size();
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++){
      if(arr[i]>0) pos.push_back(arr[i]);
       else neg.push_back(arr[i]);
     }
  // Positives on even indices, negatives on odd.
    for(int i=0;i<n/2;i++){
      
      arr[2*i] = pos[i];
      arr[2*i+1] = neg[i];
  }


   // Indices for positive and negative vectors
    // int i = 0, j = 0;
    // int idx = 0;
    
    // // Rearrange positives at even indices and negatives at odd indices
    // while(i < pos.size() && j < neg.size()) {
    //     arr[idx++] = pos[i++];  // Place positive at even index
    //     if (idx < n) {
    //         arr[idx++] = neg[j++]; // Place negative at odd index
    //     }
    // }
    
    // // If there are leftover positives, place them in the remaining positions
    // while(i < pos.size() && idx < n) {
    //     arr[idx++] = pos[i++];
    // }
    
    // // If there are leftover negatives, place them in the remaining positions
    // while(j < neg.size() && idx < n) {
    //     arr[idx++] = neg[j++];
    // }
    
}

// taking extra single array  and in single pass 
void better(vector<int>& arr)     //o(n) + o(n)
{
    int n=arr.size();
    vector<int>ans(n);
    int pos=0,neg=1;
    for(int i=0;i<n;i++)
    {
       if(arr[i]<0) 
       {
        ans[pos]=arr[i];
        pos+=2;
       }
       else 
       {
        ans[neg]=arr[i];
        neg+=2;
       }
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;

}


int optimal(vector<int>& arr)   //o(n) + o(1)  
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
    brute(arr);
    better(arr);
   optimal(arr);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

}