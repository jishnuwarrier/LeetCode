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
    
    ListNode* merge(ListNode* a, ListNode* b){

        if(!a)
            return b;
        if(!b)
            return a;
        
        if(a->val > b->val)
            swap(a, b);
            
        ListNode* head = a;
        ListNode* list = head;
        a = a->next;
                
        while(a && b){
            if(a->val <= b->val){
                list->next = a;
                a = a->next;
            } 
            
            else{
                list->next = b;
                b = b->next;
            }
            
            list = list->next;
        }
        
        for(; a; list->next = a, a = a->next, list = list->next);
        for(; b; list->next = b, b = b->next, list = list->next);
            
        return head;
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(!head)
            return NULL;
        
        if(!head->next)
            return head;
        
        ListNode* prev = head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        prev->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
};