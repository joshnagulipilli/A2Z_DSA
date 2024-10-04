
#include<bits/stdc++.h>
using namespace std;



void brute(vector<vector<int>>& arr,int n,int m)     //o(n*m + n*m) + o(n*m)
{  
     vector<vector<int>>ans(n,vector<int>(m));
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            ans[j][n-i-1]=arr[i][j];
        }
     }
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
     }


}


void better(vector<vector<int>>& arr,int n,int m)    //
{

}

//transpose and reverse

void optimal(vector<vector<int>>& arr,int n ,int m)   //o(n*m + n) = o(1)
{
     for(int i=0;i<n-1;i++) // doesnt change diagonal which is last element
     {
        for(int j=i+1;j<m;j++)    // doesnt change first element
        {
            swap(arr[i][j],arr[j][i]);
        }
        }
        for(int i=0;i<n;i++){
        reverse(arr[i].begin(),arr[i].end());
     }
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
     }
    
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
        cin>>arr[i][j];
        }
    }
//    brute(arr,n,m);
    // better(arr,n,m);
    optimal(arr,n,m);
    //  for(int i=0;i<n;i++)
    //  {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    //  }

}