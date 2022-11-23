/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    int n = 0;
    
    int nodeno(Node* head){
        int posfromend = 0;
        for(Node* curr=head; curr; curr=curr->next, posfromend++);
        return n-posfromend;
    }
    
    Node* copyRandomList(Node* head) {
        
        if(!head) return NULL;
        for(Node* curr = head; curr; curr=curr->next, n++);
        vector<int> rand(n);
        
        int i=0;
        for(Node* curr = head; curr; curr=curr->next, i++)
            rand[i] = nodeno(curr->random);

        Node* newhead = new Node(head->val);
        Node* curr = head;
        Node* newcurr = newhead;
        
        map<int, Node*> map;
        map[n] = NULL;
        for(int i=0; i<n-1; i++, curr=curr->next, newcurr=newcurr->next){
            newcurr->val = curr->val;
            newcurr->next = new Node(curr->next->val);
            map[i] = newcurr;
        }
        map[n-1] = newcurr;
        newcurr->next = NULL;
        
        newcurr = newhead;
        for(int i=0; i<n; i++, newcurr=newcurr->next)
            newcurr->random = map[rand[i]];

        return newhead;
    }
};