/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-11-05
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
    {
        TreeNode *node = build(inorder.begin(), postorder.begin(), inorder.size());
        
        return node;
    }
    
    TreeNode *build(vector<int>::iterator inorder, vector<int>::iterator postorder, int length)
    {
        TreeNode *node = NULL;
        if (length == 0) return node;
        vector<int>::iterator it = find(inorder, inorder+length,*(postorder+length-1));
        node = new TreeNode(*it);
        node->left = build(inorder, postorder, it-inorder);
        node->right = build(it+1, postorder+(it-inorder), length-(it-inorder)-1);
        return node;
    } 
};