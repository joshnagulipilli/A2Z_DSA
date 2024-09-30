
#include<bits/stdc++.h>
using namespace std;

void brute(vector<int>& arr1,vector<int>& arr2)   //      o(nlogn + mlogm + (n+m)) + o(n+m) 
{

    //only use set not unordered_set
    set<int>st;                     // o(logn) for set  
    for(int i=0;i<arr1.size();i++) //o(nlogn) for set insert
    {
        st.insert(arr1[i]);
    } 
    for(int i=0;i<arr2.size();i++) //o(mlogm)
    {
        st.insert(arr2[i]);
    } 
    for(auto it:st)    
    {
        cout<<it<<" ";
    }

}
int better(vector<int>& arr1,vector<int>& arr2)
{

}
void optimal(vector<int>& arr1,vector<int>& arr2)       // o(n+m)
{
  vector<int>ans;                          //space o(n+m)
  int n=arr1.size();
  int m=arr2.size();
  int i=0,j=0;
  while(i<n && j<m)
  {
    if(arr1[i]<=arr2[j])
    {
        if(ans.size()==0 || ans.back()!=arr1[i])          //ans.back is considering last element we push into ans
        ans.push_back(arr1[i]);
        i++;
    }
    else 
    {
        if(ans.size()==0 || ans.back()!=arr2[j])
        {
            ans.push_back(arr2[j]);
            j++;
        }
    }
  }

  while(i<n)
  {
        if( ans.back()!=arr1[i])          //ans.back is considering last element we push into ans
              ans.push_back(arr1[i]);
        i++;
    
  }
  while(j<m)
  {
    if( ans.back()!=arr2[j])
        {
            ans.push_back(arr2[j]);
            j++;
        }
  }
  for(int i=0;i<ans.size();i++)
  {
    cout<<ans[i]<<" ";
  }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>arr1(n),arr2(m);
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    //  brute(arr1,arr2);
    //  better(arr1,arr2);
    optimal(arr1,arr2);
    
}