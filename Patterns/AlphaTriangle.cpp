// E
// D E
// C D E
// B C D E 
// A B C D E

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        char a='A'+(n-i);
        for(int j=1;j<=i;j++)
        {
            cout<<a<<" ";
            a++;
        }
        
        cout<<endl;
    }
}


// E
// E D
// E D C
// E D C B
// E D C B A

//for this pattern we code
// for(int i=1;i<=n;i++)
// {
//     char a='A'+n-1;
//     for(int j=1;j<=i;j++)
//     {
//          cout<<a<<" ";
//          a--;
//     }
//     cout<<endl;
// }
