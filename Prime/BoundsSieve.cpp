// #include<bits/stdc++.h>
// using namespace std;


// int n= 100000000;
// bool sieve[1000000001];

// void createSieve()
// {
//     for(int i=0;i<=n;i++) // o(n)
//     {
//          sieve[i]=true;
//     }

//     for(int i=2;i*i<=n;i++)    // log 
//     {
//         if(sieve[i]==true)  // only consider when it is not multiple of any previous numbers
//         {
//             for(int j=i*i;j<=n;j+=i)    // log    ==> both loops  log(log n)
//             {
//                 sieve[j]=false;
//             }
//         }
//     }
//  // 5*10^6  more than range 
//     int limit = 5 * 1000000;
//     int cnt=0;
//     int size=1;
//     for(int i=2;;i++)
//     {
//         if(sieve[i]==true)
//         {
//             cnt++;
//         }
//         if(cnt==limit)
//         {
//             size=i;
//             break;
//         }
//     }
//         cout<<size;
// } 





// int main()
// {
//     createSieve();
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int N;
//         cin>>N;
//         if(sieve[N]==true)
//         {
//             cout<<"YES";

//         }
//         else {
//             cout<<"NO";
//         }
//     }
// }








// from above code we get the last 5 * 10^6 prime number , so we can take range upto 860281211 is enough .
// so take arr and push all primes from sieve


#include<bits/stdc++.h>
using namespace std;


int n = 86028121;
vector<int>sieve(n+1);
//bool sieve[n+1] gives error . since integral constant
vector<int>ds;
void createSieve()
{
    for(int i=0;i<=n;i++) // o(n)
    {
         sieve[i]=true;
    }

    for(int i=2;i*i<=n;i++)    // log 
    {
        if(sieve[i]==true)  // only consider when it is not multiple of any previous numbers
        {
            for(int j=i*i;j<=n;j+=i)    // log    ==> both loops  log(logvn)
            {
                sieve[j]=false;
            }
        }
    }
 // 5*10^6  more than range 
    // int limit = 5 * 1000000;
    // int cnt=0;
    // int size=1;
    // for(int i=2;;i++)
    // {
    //     if(sieve[i]==true)
    //     {
    //         cnt++;
    //     }
    //     if(cnt==limit)
    //     {
    //         size=i;
    //         break;
    //     }
    // }
    //     cout<<size;



    for(int i=2;i<=n;i++)
    {
      if(sieve[i]==true)
      {
        ds.push_back(i);
      }
    }

} 





int main()
{
    createSieve();
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        cout<<ds[N-1];
    }
}

