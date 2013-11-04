/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-11-04
 * Email		: luoshikai@gmail.com
 *************************************/


/**************************************
 * Given a binary tree, return the zigzag level order traversal of its 
 * nodes' values. (ie, from left to right, then right to left for the next 
 * level and alternate between).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 * confused what "{1,#,2,3}" means? > read more on how binary tree is 
 * serialized on OJ.
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) 
    {
        vector<vector<int> > res;
        zigzagLevelOrderRe(root, 0, res);
        
        for (int i = 0; i < res.size(); ++i)
        {
            if (i & 0x1) reverse(res[i].begin(), res[i].end());  
        }
        return res;
    }
    
    void zigzagLevelOrderRe(TreeNode *root, int level, vector<vector<int> > &res)
    {
        if (root == NULL) return;
        
        if (level >= res.size()) res.push_back(vector<int>());
        res[level].push_back(root->val);
        
        zigzagLevelOrderRe(root->left, level + 1, res);
        zigzagLevelOrderRe(root->right, level + 1, res);
    }
};