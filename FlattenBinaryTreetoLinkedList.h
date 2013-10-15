/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-15
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example,
 * Given
 *
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 * The flattened tree should look like:
 *    1
 *     \
 *      2
 *       \
 *        3
 *         \
 *          4
 *           \
 *            5
 *             \
 *              6
 * click to show hints.
 *
 * Hints:
 * If you notice carefully in the flattened tree, each node's right child 
 * points to the next node of a pre-order traversal.
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
public:
    void flatten(TreeNode *root) 
    {
        flattenRe(root);
    }
    
    void flattenRe(TreeNode *node)
    {
        if (node == NULL) return;
        
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        if (node->left != NULL)
        {
            TreeNode *mostRight = rightMost(node->left);
            mostRight->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }
        flattenRe(left);
        flattenRe(right);
    }
    
    TreeNode *rightMost(TreeNode *node)
    {
        TreeNode *ptr = node;
        while (ptr->right != NULL)
        {
            ptr = ptr->right;
        }
        return ptr;
    }
};