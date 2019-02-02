#include <iostream>
#include <array>

using namespace std;

//function to take input for the array
void take_input(long long* arr, long long n)
{
	for(long long i=0; i<n; i++)
	{
		cin >> arr[i];
	}
}

//function to rotate the array leftwards by d rotations
void left_rotation(long long* arr, long long n, long long d)
{
	for(long long i=0; i<n; i++)
	{
		cout << arr[(i+d)%n] << " ";
	}
	cout << endl;
}

//main function
int main()
{
	long long n,d;
	long long arr[100000];
	cin >> n >> d;
	take_input(arr, n);
	left_rotation(arr, n, d);
	return 0;
}