/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-28
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric 
 * around its center).
 *
 * For example, this binary tree is symmetric:
 *
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * But the following is not:
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 *
 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 * 
 * 
 * OJ's Binary Tree Serialization:
 * The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.
 * 
 * Here's an example:
 *    1
 *   / \
 *  2   3
 *     /
 *    4
 *     \
 *      5
 * The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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
    bool isSymmetric(TreeNode *root) 
    {
        vector<int> res;
        isSymmetricRe(root, res);
        
        for (int i = 0, j = res.size() - 1; i < j; ++i, --j)
        {
            if (res[i] != res[j])
            {
                return false;
            }
        }
        
        return true;
    }

    void isSymmetricRe(TreeNode *node, vector<int> &res)
    {
        if (node == NULL) return;
        
        isSymmetricRe(node->left, res);
        res.push_back(node->val);
        isSymmetricRe(node->right, res);
        
        return;
    }
};