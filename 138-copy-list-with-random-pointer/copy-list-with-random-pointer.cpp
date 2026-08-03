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
        unordered_map<Node*,Node*> old_copy;
        Node* curr=head;
        while(curr!=nullptr){
            old_copy[curr] = new Node(curr->val);
            curr=curr->next;
        }
        curr=head;
        while(curr!=nullptr){
            Node* copy=old_copy[curr];
            copy->next=old_copy[curr->next];
            copy->random=old_copy[curr->random];
            curr=curr->next;
        }
        return old_copy[head];
    }
};