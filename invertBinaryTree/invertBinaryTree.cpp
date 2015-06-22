#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
    	if (root->left != NULL || root->right != NULL)
    	{
    		TreeNode *temp = root->left;
    		root->left = root->right;
    		root->right = temp;
    		invertTree(root->left);
    		invertTree(root->right);
    	}
    }
};


int main()
{
	TreeNode a(4);
	TreeNode b(2);
	TreeNode c(7);
	TreeNode d(1);
	TreeNode e(3);
	TreeNode f(6);
	TreeNode g(9);

	Solution sol;
	return 0;
}
