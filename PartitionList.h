/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-23
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * Given a linked list and a value x, partition it such that all nodes less 
 * than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x) 
    {
        if (head == NULL) return head;
        ListNode headptr(0);
        headptr.next = head;
        ListNode *ptr = &headptr;
        ListNode *insert = &headptr;
        
        while (ptr->next)
        {
            ListNode *cur = ptr->next;
            if (cur->val >= x)
            {
                ptr = ptr->next;
            }
            else
            {
                if (ptr == insert)
                {
                    ptr = ptr->next;
                    insert = insert->next;
                }
                else
                {
                    ptr->next = cur->next;
                    cur->next = insert->next;
                    insert->next = cur;
                    insert = insert->next;
                }
            }
        }
        
        return headptr.next;
    }
};