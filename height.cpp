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
		
		//vector< int > count;
		int height(Node *root)
		{	
			if(root==NULL)
				return -1;
			else
			{
				int left = 1 + height(root->left);
				int right = 1 + height(root->right);
				if(left>right)
					return left;
				else
					return right;
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
	cout << "The height of the tree is ";
	int h = mytree.height(root);
	cout << h << ".";
	cout << endl;
	return 0;
}










