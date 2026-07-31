/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* dfs(Node* head) {
        Node* curr=head;
        Node* last=head;
        while(curr!=nullptr){
            Node* next=curr->next;
            if(curr->child){
                Node* childhead=curr->child;
                Node* childtail=dfs(childhead);
                curr->next=childhead;
                childhead->prev=curr;
                if(next){
                    childtail->next=next;
                    next->prev=childtail;
                }
                curr->child=nullptr;
                last=childtail;
                curr=childtail;
            }
            else{
                last=curr;
            }
            curr=curr->next;
        }
        return last;
    }
    Node* flatten(Node* head){
        if(head==nullptr)
           return nullptr;
        dfs(head);
        return head;
    }
};