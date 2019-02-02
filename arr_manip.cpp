#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long int n,m,a,b,k,max = 0, x = 0;
    cin >> n >> m;
    long int *arr = new long int[n+1]();
    for(long int i=0; i<m; i++)
    {
        cin >> a >> b >> k;
        arr[a]  += k;
        if((b+1)<=n) 
            arr[b+1] -= k;
    }
    for(long int i=1; i<=n; i++)
    {
       x = x + arr[i];
       if(max<x)
           max=x;

    }

    cout<<max;
    return 0;
}
