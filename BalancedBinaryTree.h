/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-31
 * Email		: luoshikai@gmail.com
 *************************************/


/**************************************
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree 
 * in which the depth of the two subtrees of every node never differ by more 
 * than 1.
 *************************************/
 
 
 
class Solution
{
public:
	bool isBalanced(TreeNode *root)
	{
		int height = 0;
		return isBalancedRe(root, height);
	}

	bool isBalancedRe(TreeNode *node, int &height)
	{
		if (node == NULL)
		{
			height = 0;
			return true;
		}

		int leftHeight = 0, rightHeight = 0;

		if (isBalancedRe(node->left, leftHeight) && isBalancedRe(node->right, rightHeight))
		{
			if (abs(leftHeight - rightHeight) <= 1)
			{
				height = leftHeight > rightHeight ? leftHeight+1 : rightHeight+1;
				return true;
			}
		}

		return false;
	}
};s