class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* H = new ListNode(-1, head);
        ListNode* h1 = H, *h2 = H->next;
        while (h1 && h2) {
            ListNode* h3 = h2->next;
            if (h3) {
                h1->next = h3;
                h2->next = h3->next;
                h3->next = h2;
            }
            h1 = h2;
            h2 = h1->next;
        }
        return H->next;
    }
};