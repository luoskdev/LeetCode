/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-10
 * Email		: luoshikai@gmail.com
 *************************************/

 
/**************************************
 * Given a linked list, remove the nth node from the end of list and return 
 * its head.
 * 
 * For example,
 *
 *   Given linked list: 1->2->3->4->5, and n = 2.
 *
 *   After removing the second node from the end, the linked list becomes 
 * 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) 
    {
        ListNode *first = head, *second = head;
        while (n--)
        {
            first = first->next;
        }
        
        if (first == NULL)
        {
            head = head->next;
            delete second;
            
            return head;
        }
        
        while (first->next)
        {
            first = first->next;
            second = second->next;
        }
        
        ListNode *temp = second->next;
        second->next = temp->next;
        delete temp;
        
        return head;
    }
};
