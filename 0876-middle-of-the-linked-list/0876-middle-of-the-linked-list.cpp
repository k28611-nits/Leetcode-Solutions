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
    ListNode* middleNode(ListNode* head) {
        if(head->next==NULL) return head;
    
        ListNode* temp= head;
        int count=1;
        while(temp->next!=NULL)
        {
            count++;temp=temp->next;
        }
        int c=0;
        temp=head;
        while(temp->next!=NULL)
        {
            c++;temp=temp->next;
            if(c==(count/2))
                return temp;
        }
     return NULL;   
    }     
};