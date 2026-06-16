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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        int length=0;
        while(curr!=nullptr){
            length++;
            curr=curr->next;
        }
        if(length == n){
            return head->next;
        }
        int count=length-n-1;
        ListNode* temp=head;
        while(count>0){
            temp=temp->next;
            count--;
        }
        temp->next=temp->next->next;
        return head;
    }
};