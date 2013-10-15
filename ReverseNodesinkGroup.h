/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-15
 * Email		: luoshikai@gmail.com
 *************************************/
 

/**************************************
 * Given a linked list, reverse the nodes of a linked list k at a time and 
 * return its modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in the end
 * should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
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
    ListNode *reverseKGroup(ListNode *head, int k) 
    {
        int len = length(head);
        int times = len / k;
        ListNode headptr(0);
        headptr.next = head;
        
        ListNode *ptr = &headptr;
        ListNode *cur = head;
        
        while (times--)
        {
            for (int i = 1; i < k; ++i)
            {
                ListNode *move = cur->next;
                cur->next = move->next;
                move->next = ptr->next;
                ptr->next = move;
            }
            ptr = cur;
            cur = ptr->next;
        }
        return headptr.next;
    }
    
    int length(ListNode *head)
    {
        int res = 0;
        ListNode *ptr = head;
        while (ptr != NULL)
        {
            ptr = ptr->next;
            ++res;
        }
        return res;
    }
};