/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-23
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * Given a sorted linked list, delete all duplicates such that each element 
 * appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
    ListNode *deleteDuplicates(ListNode *head) 
    {
        ListNode *ptr = head;
        
        while (ptr != NULL && ptr->next != NULL)
        {
            if (ptr->val == ptr->next->val)
            {
                ListNode *p = ptr->next;
                ptr->next = p->next;
                delete p;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        
        return head;
    }
};