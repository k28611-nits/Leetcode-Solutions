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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* s=head, *f=head;
        
		int i=k-1;           
        
		while(i-- && f->next)
            f=f->next; 
        
        ListNode* temp =f;
        
        while(f->next) 
        {
            s=s->next;
            f=f->next;
        }
        
        swap(temp->val , s->val);
        
        return head;
    }
};