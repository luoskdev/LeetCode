/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-10
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
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
    ListNode *mergeKLists(vector<ListNode *> &lists) 
    {
        ListNode *head = NULL, *ptr = NULL;
        
        while(true)
        {
            ListNode *temp = getMin(lists);
            if (temp == NULL) break;
            if (head == NULL) 
            {
                head = temp;
                ptr = head;
            }
            else
            {
                ptr->next = temp;
                ptr = ptr->next;
            }
        }
        
        return head;
    }
    
    ListNode *getMin(vector<ListNode *> &lists)
    {
        int imin = -1;
        ListNode *res = NULL;
        
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i] == NULL) continue;
            if (imin == -1 || lists[i]->val < lists[imin]->val) imin = i;
        }
        if (imin != -1)
        {
            res = lists[imin];
            lists[imin] = res->next;
        };
        
        return res;
    }
};