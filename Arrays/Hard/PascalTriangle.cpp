
#include<bits/stdc++.h>
using namespace std;


int varient1(int n,int r , int c)    
{  
   //this method id ncr ==> (n!/(r! * (n-r)!))
   r=r-1,c=c-1;
   int ans=1;
   for(int i=0;i<c;i++)
   {
    ans=ans*(r-i);
    ans=ans/(i+1);
   }
   return ans;
}

int fun(int row,int col)
{
    int res=1;
    for(int i=0;i<col;i++)
    {
        res=res*(row-i);
        res=res/(i+1);
    }
    return res;
}


vector<int> varient2(int row)    
{
   vector<int>ans;
   for(int col=1;col<=row;col++)
   {
    ans.push_back(fun(row-1,col-1));
   }
   return ans;

//  long long ans = 1;
//     cout << ans << " "; // printing 1st element
//     //Printing the rest of the part:
//     for (int i = 1; i < n; i++) {
//         ans = ans * (n - i);
//         ans = ans / i;
//         cout << ans << " ";
//     }
//     cout << endl;

}

vector<int> addit(int r)
{
     vector<int>v;
     int ans=1;
     v.push_back(1);
     for(int col=1;col<r;col++)
     {
        ans=ans*(r-col);
        ans=ans/col;
        v.push_back(ans);
     }
     return v;
}

vector<vector<int>> varient3(int n)  
{
   vector<vector<int>>ans;
   for(int i=1;i<=n;i++)
   {
    ans.push_back(addit(i));
   }
   return ans;
}
int main()
{
    // int row,col,n;
    // cin>>n>>row>>col;
    // cout<<varient1(n,row,col)<<endl;
    // vector<int>ans=varient2(n);
    // for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    int n;
    cin>>n;
    vector<vector<int>>arr=varient3(n);
    for(auto it:arr)
    {
        for(auto i:it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}