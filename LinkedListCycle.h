/**************************************
 * Author 	: luoshikai
 * Version 	: 1.0
 * Date 	: 2013-10-30
 * Email	: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head) 
    {
        if (head == NULL) return false;
        ListNode *fast = head, *slow = head;
        do
        {
            if (slow == NULL) break;
            else slow = slow->next;
            if (fast == NULL || fast->next == NULL) break;
            else fast = fast->next->next;
        } while (fast != NULL && fast != slow);
        
        return fast == slow;
    }
};