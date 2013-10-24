/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-23
 * Email		: luoshikai@gmail.com
 *************************************/
 

/**************************************
 * A linked list is given such that each node contains an additional random 
 * pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 *************************************/
 
 

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        RandomListNode *res = NULL;
        if (head == NULL) return res;
        
        RandomListNode *ptr = head;
        while (ptr != NULL)
        {
            RandomListNode *temp = new RandomListNode(ptr->label);
            temp->next = ptr->next;
            ptr->next = temp;
            ptr = temp->next;
        }
        
        ptr = head;
        while (ptr != NULL)
        {
            RandomListNode *temp = ptr->next;
            if (ptr->random != NULL) temp->random = ptr->random->next;
            ptr = temp->next;
        }
        
        ptr = head;
        res = head->next;
        
        while (ptr != NULL)
        {
            RandomListNode *temp = ptr->next;
            ptr->next = temp->next;
            ptr = ptr->next;
            if (ptr != NULL) temp->next = ptr->next;
        }
        
        return res;
    }
};