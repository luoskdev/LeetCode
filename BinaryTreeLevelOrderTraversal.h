/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-11-04
 * Email		: luoshikai@gmail.com
 *************************************/


/**************************************
 * Given a binary tree, return the level order traversal of its nodes' values. 
 * (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 * confused what "{1,#,2,3}" means? > read more on how binary tree is 
 * serialized on OJ.
 *
 *
 * OJ's Binary Tree Serialization:
 * The serialization of a binary tree follows a level order traversal, where 
 * '#' signifies a path terminator where no node exists below.
 *
 * Here's an example:
 *   1
 *  / \
 * 2   3
 *    /
 *   4
 *    \
 *     5
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
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<vector<int> > res;
        levelOrderRe(root, 0, res);
        return res;
    }
    void levelOrderRe(TreeNode *root, int level, vector<vector<int> > &res)
    {
        if (root == NULL) return;
        if (level >= res.size()) res.push_back(vector<int>());
        res[level].push_back(root->val);
        levelOrderRe(root->left, level + 1, res);
        levelOrderRe(root->right, level + 1, res);
    }
    
    vector<vector<int> > levelOrder_1(TreeNode *root) 
    {
        vector<vector<int> > res;
        deque<TreeNode*> queue;
        queue.push_back(root);
        queue.push_back(NULL);
        while(queue.front() != NULL)
        {
            vector<int> v_t;
            while (true)
            {
                TreeNode *temp = queue.front();
                queue.pop_front();
                if (temp == NULL) break;
                v_t.push_back(temp->val);
                if (temp->left != NULL) queue.push_back(temp->left);
                if (temp->right != NULL) queue.push_back(temp->right);
            }
            queue.push_back(NULL);
            res.push_back(v_t);
        }
        
        return res;
    }
};