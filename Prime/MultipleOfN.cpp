// problem states that how many numbers from the range 1 - 10^6 have  n as a minimum prime factor
//if n=2 then it is a prime factor of 500000 numbers - 4,6,8,10,12,14.....till 5000000;
//return the count of n=2 how many numbers it is minimum prime factor

#include<bits/stdc++.h>
using namespace std;

int n=1000000;
vector<int>sieve(n+1);
void createSieve()
{
    for(int i=2;i<=n;i++)
    {
        sieve[i]=1;
    }
    for(int i=2;i*i<=n;i++)
    {
        if(sieve[i]==1)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                if(sieve[j]!=0)
                {
                    sieve[i]++;
                    sieve[j]=0;
                }
            }
        }
    }
}



int main()
{
    createSieve();
    int N;
    cin>>N;
    cout<<sieve[N];
}