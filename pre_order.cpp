#include <iostream>

using namespace std;

class Node
{
	public:
		int data;
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
		
		
		void pre_order(Node *root)
		{
			if(root==NULL)
				return;
			cout << root->data << " ";
			if(root->left)
				pre_order(root->left);
			if(root->right)
				pre_order(root->right);
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
	cout << "From pre-order traversal, we get : ";
	mytree.pre_order(root);
	cout << endl;
	return 0;
}










