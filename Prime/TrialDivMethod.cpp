#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if(n==1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i+=6)
    {
        if( n % i == 0 || n % (i+2) == 0) //here we check for 11 and 13 . every number have 6 diff and 2 diff
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
    cout<<isPrime(n);
}