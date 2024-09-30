
//in-place and have to return size of array;


#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>& arr)  
{
   set<int>st;                                  //o(nlogn + n) + o(n)
   for(int i=0;i<arr.size();i++)
   {
    st.insert(arr[i]);
   }
   int index=0;
   for(auto it:st)
   {
      arr[index++]=it;
   }
    return index;
}
int better(vector<int>& arr)
{

}
int optimal(vector<int>& arr)       //o(n) + o(1)
{
     int ind=0;
     for(int j=1;j<arr.size();j++)
     {
        if(arr[ind]!=arr[j])
        {
            arr[ind+1]=arr[j];
            ind++;
        }
     }
     return ind+1;
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