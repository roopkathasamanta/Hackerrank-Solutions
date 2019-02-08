#include <iostream>
#include <stack>

using namespace std;

int main() 
{
	//two stacks are created, one for normal and another two keep track of the maximum element
    stack<long int> s, m;
    //first max element is considered to be -1
    m.push(-1);
    int n; 
    cin >> n;
    int  i = 0;
    while(i<n)
    {
        int x;
        // x is the variable for the type
        cin>>x;
        if(x==1)
        {
            int z;
            //z is pushed into the stack s
            cin >> z;
            s.push(z);
            //if z is greater than the top-most element of the stack m, z is pushed into the stack
        	if(z >= m.top())
        		m.push(z);
        }
        else if(x==2)
        {
            int q = s.top();
            if(q == m.top())
                m.pop();
            s.pop();
        }
        else if(x==3)
            cout << m.top() << endl;
        i++;
    }
    return 0;
}