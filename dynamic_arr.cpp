#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long n,q;
	cin >> n >> q;
	vector <vector <int> > seq(n,vector <int> ());
	int ans = 0;
	for(long i=0; i<q; i++) 
	{
    	long long t,x,y;
    	cin >> t >> x >> y;

    	if (t==1) 
    	{
        	seq[(x^ans)%n].push_back(y);
    	}
    	else 
    	{
        	ans=seq[(x^ans)%n][y%seq[(x^ans)%n].size()];
        	cout << ans << endl;
    	}
	}
	return 0;
}