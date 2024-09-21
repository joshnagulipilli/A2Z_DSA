// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n; 
//     for(int i=2;i<=n;i++)    //o(n^2) if it is not a prime number 
//     {
//         while(n%i==0)
//         {
//             cout<<i<<" ";
//             n/=i;
//         }
//     }
//     // worst case o(n) -> this is for prime number , the inner never executes as prime is not divisible . 
//     return 0;
// }

//o(n)   --> o(sqrt(n))

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n; 
    for(int i=2;i*i<=n;i++)    //o(sqrt(n)) 
    {
        while(n%i==0)
        {
            cout<<i<<" ";
            n/=i;
        }
    }
    if(n>1) cout<<n; // last left out prime and also if a number given is prime.
    return 0;
}






