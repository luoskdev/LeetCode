/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-11-05
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
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
    TreeNode *sortedArrayToBST(vector<int> &num) 
    {
        TreeNode *head = NULL;
        if (num.empty()) return head;
        
        sortedArrayToBSTRe(num, head, 0, num.size());
        
        return head;
    }
    
    void sortedArrayToBSTRe(vector<int> &num, TreeNode *&node, int start, int length)
    {
        int mid = start + length / 2;
        if (length <= 0 || start >= num.size()) 
        {
            node = NULL;
            return;
        }
        
        node = new TreeNode(num[mid]);
        sortedArrayToBSTRe(num, node->left, start, mid-start);
        sortedArrayToBSTRe(num, node->right, mid+1, length-(mid-start)-1);
        
        return;
    }
};