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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
 
        int n = 0;
        for(ListNode* temp = head; temp != NULL; temp = temp->next, n++);
        
        if(k == n)
            return head->next;
        
        k = n-k;
         
        for(ListNode* curr = head; curr->next != NULL; curr = curr->next, k--){
            if(k == 1){
                curr->next = curr->next->next;
                return head;
            }
        }
            
        return NULL;
    }
};