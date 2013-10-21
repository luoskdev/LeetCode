/**************************************
 * Author       : luoshikai
 * Version      : 1.0
 * Date         : 2013-10-22
 * Email        : luoshikai@gmail.com
 *************************************/

/**************************************
 * Given a list, rotate the list to the right by k places, where k is
 * non-negative.
 * 
 * For example :
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 *************************************/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        int length = 0;
        ListNode *front = head, *back = head;
        while (front != NULL)
        {
            ++length;
            front = front->next;
        }

        if (length <= 1) reutrn head;
        k %= length; front = head;
        if (k == 0) return head;

        while (k--)
        {
            front = front->next;
        }

        while (front->next != NULL)
        {
            front = front->next;
            back = back->next;
        }

        front->next = head;
        head = back->next;
        back->next = NULL;

        return head;
    }
}
