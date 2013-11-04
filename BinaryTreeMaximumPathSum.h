/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-11-04
 * Email		: luoshikai@gmail.com
 *************************************/


/**************************************
 * Given a binary tree, find the maximum path sum.
 *
 * The path may start and end at any node in the tree.
 *
 * For example:
 * Given the below binary tree,
 *
 *        1
 *       / \
 *      2   3
 * Return 6.
 *************************************/
 
 
 
 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int res;
public:
    int maxPathSum(TreeNode *root) 
    {
        res = INT_MIN;
        
        return max(res, maxPathSumRe(root));
    }
    
    int maxPathSumRe(TreeNode *node)
    {
        if (node == NULL) return 0;
        
        int left = maxPathSumRe(node->left);
        int right = maxPathSumRe(node->right);
        int sum = max(node->val, max(left, right)+node->val);
        
        res = max(res, sum);
        res = max(res, node->val+left+right);
        
        return sum;
    }
};