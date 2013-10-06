/**************************************
 * Author 	: luoshikai
 * Version 	: 1.0
 * Date 	: 2013-10-06
 * Email	: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * You are given two linked lists representing two non-negative numbers. The 
 * digits are stored in reverse order and each of their nodes contain a single 
 * digit. Add the two numbers and return it as a linked list.
 *************************************/

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
    {
        int carry = 0, sum = 0;
        ListNode *p1 = l1, *p2 = l2, *head = NULL, *cur = NULL;
        
        while (p1 || p2)
        {
            sum = 0;
            if (p1) {sum += p1->val; p1 = p1->next;}
            if (p2) {sum += p2->val; p2 = p2->next;}
            
            if (head == NULL) {head = new ListNode(sum % 10); cur = head;}
            else {cur->next = new ListNode((sum + carry) % 10); cur = cur->next;}
            carry = (sum + carry) / 10;
        }
        if (carry) {cur->next = new ListNode(1);}
        
        return head;
    }
};