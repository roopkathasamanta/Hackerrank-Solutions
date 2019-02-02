#include <iostream>
#include <queue>
#include <map>

using namespace std;

class Node
{
	public:
		int data;
		int hd;
		Node *left;
		Node *right;
		Node(int d)
		{
			data = d;
			left = NULL;
			right = NULL;
		}
};


class solution
{
	public:
		Node* insert(Node* root, int data)
		{
			if(root==NULL)
				return new Node(data);
			else
			{
				Node* cur;
				if(data<=root->data)
				{
					cur = insert(root->left, data);
					root->left = cur;
				}
				else
				{
					cur = insert(root->right, data);
					root->right = cur;
				}
				
				return root;
			}
		}
		map<int, pair<int,int> > horzView;
		int max_dist=0,min_dist=0;

		//Iterators are used to point at memory addresses of STL containers
		//Maps are associative containers that store elements in a mapped fashion
		/*The pair container is a simple container defined in <utility> header consisting of two data elements or objects.

		The first element is referenced as ‘first’ and the second element as ‘second’ and the order is fixed (first, second).
		Pair is used to combine together two values which may be different in type. Pair provides a way to store two heterogeneous objects as a single unit.*/
		
		map<int, pair<int,int> >::iterator it;


    	void DFS(Node* root,int horz,int depth) 
    	{
			it = horzView.find(horz);
           	if(it==horzView.end())
            {
                pair<int,int> val(depth,root->data);
                horzView.insert( pair<int, pair<int,int> >(horz,val));
                
                if(horz > max_dist)
                     max_dist=horz;
                 
                if(horz < min_dist)
                     min_dist=horz;
            }
        	else
            {
                pair<int,int> tmpDist = horzView[horz];
                if(tmpDist.first > depth )
                {
                    pair<int,int> val(depth,root->data);
                    horzView.erase(horz);
                    horzView.insert( pair<int, pair<int,int> >(horz,val));
                
                    if(horz > max_dist)
                       max_dist=horz;
                
                    if(horz < min_dist)
                        min_dist=horz;

                }
                    
            }       
        

        if(root->left!=NULL)
        {   
          //  cout<<"\n"<<root->data<<" calling "<<root->left->data<<"  at "<<horz-1<<endl;
            DFS(root->left,(horz-1),(depth+1));
            //DFS(root->left,--horz,++depth);       #ERROR#ERROR....changes the value of horz when calling the next func.
        }    

        if(root->right!=NULL)
        {
            //cout<<"\n"<<root->data<<" calling "<<root->right->data<<"  at "<<horz+1<<endl;
            DFS(root->right,(horz+1),(depth+1));
            //DFS(root->right,++horz,++depth);
        }
    }





    void topView(Node * root) 
    {
        DFS(root,0,0);

        //cout<<endl;
       // cout<<min_dist<<" "<<max_dist<<endl;
        

        for(int i = min_dist; i<=max_dist ; i++)
            {
                cout<<horzView[i].second<<" ";
            }

    }


};


int main()
{
	solution mytree;
	Node* root = NULL;
	
	int t;
	int data;
	cout << "Enter the number of inputs: ";
	cin >> t;
	
	while(t>0)
	{
		cin >> data;
		root = mytree.insert(root, data);
		
		t--;
	}
	mytree.top_view(root);
	cout << endl;
	return 0;
}










