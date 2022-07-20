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
    void reverse(ListNode* s, ListNode* e) {
        ListNode* prev=NULL;
        ListNode* curr=s;
        ListNode* nextptr=s->next;
        while(prev!=e)
        {
            nextptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL or head->next==NULL or k==1) return head;
        ListNode* s=head;ListNode* e=head;
        int inc=k-1;
        while(inc--)
        {
            e=e->next;
            if(e==NULL) return head;
        }
        ListNode* nexthead=reverseKGroup(e->next,k);
        reverse(s,e);
        s->next=nexthead;
        return e;
    }
};