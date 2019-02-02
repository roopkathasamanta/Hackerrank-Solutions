#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string,int> m;
    int n,q;
    string s;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> s;
        m[s]++;
    }
    
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> s;
        cout << m[s] << endl;
    } 

    return 0;
}
