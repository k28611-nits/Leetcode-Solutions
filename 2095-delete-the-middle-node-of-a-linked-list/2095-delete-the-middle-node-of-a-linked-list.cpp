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
	ListNode* deleteMiddle(ListNode* head) {
		   if(head->next==nullptr) return nullptr;
		   ListNode *f=head;
		   ListNode *s=head,*prev;
		  while(f!=nullptr && f->next!=nullptr){
			  f=f->next->next;
			  prev=s;
			  s=s->next;
		  }
		prev->next=prev->next->next;
		return head;
	}
};