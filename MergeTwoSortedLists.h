/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-13
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists. 
 *************************************/
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
    {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode *res = NULL;
        
        if (l1->val < l2->val)
        {
            res = l1;
            res->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            res = l2;
            res->next = mergeTwoLists(l1, l2->next);
        }
        
        return res;
    }
};