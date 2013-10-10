/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-10
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values
 * in the list, only nodes itself can be changed.
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
    ListNode *swapPairs(ListNode *head) 
    {
        if (head == NULL)
        {
            return head;
        }
        ListNode *front = head->next;
        ListNode *back = head;
        
        while (front != NULL)
        {
            int temp = front->val;
            front->val = back->val;
            back->val = temp;
            
            back = front->next;
            if (back != NULL)
            {
                front = back->next;
            }
            else
            {
                break;
            }
        }
        
        return head;
    }
};