int i=0;
    if(n==1) cout<<"No";
    else{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) 
        {
            cout<<"NO";
            break;
        }
    }
    if(i*i>n) cout<<"No";
    else cout<<"Yes";
    }
    return 0;
}
