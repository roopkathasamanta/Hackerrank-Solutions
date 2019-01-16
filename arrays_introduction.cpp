#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n, temp,i,j;
    cin >> n;
    vector<int>arr(n);
    vector<int>arr1(n);
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    for(i=0,j=n-1; i<n/2; i++, j--)
    {
      temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    for(i=0; i<n; i++)
        cout << arr[i] << " ";
    
    return 0;
}

