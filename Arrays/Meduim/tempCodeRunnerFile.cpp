        else if(b!=0)
        {
            arr[i]=1;
            b--;
        }
        else {
            arr[i]=2;
        }
    }
}

//dutch national flag algorithm

void optimal(vector<int>& arr)        // o(n) + o(1)
{
   int n=arr.size();
   int low=0,mid=0,high=n-1;
   while(mid<=high)
   {
        if(arr[mid]==1) mid++;