/**************************************
 * Author	: luoshikai
 * Version	: 1.0
 * Date		: 2013-10-28
 * Email	: luoshikai@gmail.com
 * Source	: http://oj.leetcode.com/problems/same-tree/
 *************************************/

/**************************************
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are structurally identical 
 * and the nodes have the same value.
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
    bool isSameTree(TreeNode *p, TreeNode *q) 
    {
        if (!p && !q) return true;
        else if (!p && q || p && !q) return false;
        else if (p->val != q->val) return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};