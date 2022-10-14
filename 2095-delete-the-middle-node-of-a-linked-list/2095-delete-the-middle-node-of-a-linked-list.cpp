/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
       
        if(!head->next)
            return NULL;
        
        int n=0;
        for(ListNode* curr = head; curr!= NULL; curr= curr->next, n++);
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        for(int i=1; i<n/2; i++, prev=curr, curr = curr->next);
        
        prev->next = curr->next;
        
        return head;
    }
};