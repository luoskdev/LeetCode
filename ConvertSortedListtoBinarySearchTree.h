/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-23
 * Email		: luoshikai@gmail.com
 *************************************/
 

/**************************************
 * Given a singly linked list where elements are sorted in ascending order, 
 * convert it to a height balanced BST.
 *************************************/
 
 
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int getLength(ListNode *head)
{
    int res = 0;
    while (head != NULL)
    {
        head = head->next;
        ++res;
    }
    return res;
}

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) 
    {
        return sortedListToBSTRe(head, getLength(head));
    }
    
    TreeNode *sortedListToBSTRe(ListNode *&head, int length)
    {
        if (length == 0) return NULL;
        int mid = length / 2;
        TreeNode *left = sortedListToBSTRe(head, mid);
        TreeNode *root = new TreeNode(head->val);
        TreeNode *right = sortedListToBSTRe(head->next, length - mid - 1);
        
        root->left = left;
        root->right = right;
        
        head = head->next;
        
        return root;
    }
};