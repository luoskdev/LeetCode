/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-11-05
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) 
    {
        TreeNode *head = NULL;
        
        head = buildTreeRe(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size()-1);
        
        return head;
    }
    
    TreeNode *buildTreeRe(vector<int> &preorder, vector<int> &inorder, int p_start, int p_end, int i_start, int i_end)
    {
        TreeNode *head = NULL;
        int pos = 0, len = 0;
        if (p_start > p_end) return head;
        
        head = new TreeNode(preorder[p_start]);
        for (pos = i_start; inorder[pos] != preorder[p_start]; ++pos, ++len);

        head->left = buildTreeRe(preorder, inorder, p_start+1, p_start+len, i_start, pos-1);
        head->right = buildTreeRe(preorder, inorder, p_start+len+1, p_end, pos+1, i_end);
        
        return head;
    }
};