#include<bits/stdc++.h>
using namespace std;

bool brute(vector<int>& arr)   //o(n*n) + o(1)
{
    bool flag=0;
    for(int i=0;i<arr.size()-1;i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[i]>arr[j])
            {
                return false;
            }
        }
    }
    return true;
    
}
int better(vector<int>& arr)
{

}
bool optimal(vector<int>& arr)      // o(n-1) + o(1)
{
     bool flag=0;
    
        for(int j=1;j<arr.size();j++)
        {
            if(arr[j-1]>arr[j])
            {
                return false;
            }
        
    }
    return true;
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
    // cout<<better(arr)<<endl;
    cout<<optimal(arr)<<endl;
}