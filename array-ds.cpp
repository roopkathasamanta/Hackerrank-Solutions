#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Enter the number of elements : ";
	cin >> n;
	cout << endl;
	int arr[n];
	int brr[n];
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	for(int i=0; i<n; i++)
	{
		brr[n-i-1] = arr[i];
	}
	cout << "The reversed array is : "
	for(int i=0; i<n; i++)
	{
		cout << brr[i] << " ";
	}
	cout << endl;
	return 0;
}