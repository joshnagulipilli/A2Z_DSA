
#include<bits/stdc++.h>
using namespace std;

void Row(vector<vector<int>>& arr, int n ,int m , int i)
{
    for(int j=0;j<m;j++)
    {
        if(arr[i][j]!=0)
        {
            arr[i][j]=-1;
        }
    }
}

void Col(vector<vector<int>>& arr, int n ,int m , int col)
{
    for(int j=0;j<n;j++)
    {
        if(arr[j][col]!=0)
        {
            arr[j][col]=-1;
        }
    }
}


void brute(vector<vector<int>>& arr,int n,int m)     // o(n*m)*(n*m)+o(n*m)  == o(n*m)^3    + o(1)
{  
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==0)
            {
                Row(arr,n,m,i);
                Col(arr,n,m,j);
            }
        }
     }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==-1)
                {
                    arr[i][j]=0;
                }
            }
        }

}


void better(vector<vector<int>>& arr,int n,int m)    // o(n*m) + (n*m )  + o(n+m)
{
    vector<int>row(n,0),col(m,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==0)
            {
                row[i]=1;
                col[i]=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(row[i] || col[j])
            {
                arr[i][j]=0;
            }
        }
    }
}



void optimal(vector<vector<int>>& arr,int n ,int m)  //o(n*m) + o(1)
{
    int col=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==0)
            {
                arr[j][0]=0;
                if(j!=0)
                {
                    arr[0][i]=0;
                }
                else 
                {
                    col=0;
                } 
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j]!=0)
            {
                if(arr[0][j] || arr[i][0])
                {
                    arr[i][j]=0;
                }
            }
        }
    }
    if(arr[0][0]==0)
    {
        for(int j=0;j<m;j++)
        {
            arr[0][j]=0;
        }
    }
    if(col=0)
    {
        for(int i=0;i<n;i++)
        {
            arr[i][0]=0;
        }
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
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
     }

}