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

    Node* copyRandomList(Node* head) {
        
        if(!head) return NULL;
        map<Node*, Node*> map;
        map[head] = new Node(head->val);
        
        for(Node* curr=head; curr->next; curr=curr->next){
            map[curr]->next = new Node(curr->next->val);
            map[curr->next] = map[curr]->next;
        }

        for(Node* curr=head; curr; curr=curr->next)
            map[curr]->random = map[curr->random];
        
        return map[head];
    }
};