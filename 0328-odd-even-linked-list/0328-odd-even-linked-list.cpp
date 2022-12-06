class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* head2=head->next;
        
        ListNode* odd=head,*even=head->next;
        while(odd && odd->next && odd->next->next){
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }

        odd->next=head2;
        return head;
    }
};