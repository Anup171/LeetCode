class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; 
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(auto node:lists){
            if(node!=nullptr){
                pq.push(node);
            }
        }
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while(!pq.empty()){
            ListNode *current = pq.top();
            pq.pop();
            tail->next=current;
            tail=tail->next;
            if(current->next!=nullptr){
                pq.push(current->next);
            }
        }
        return dummy->next;
    }
};