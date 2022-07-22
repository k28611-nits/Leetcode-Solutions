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
    
  ListNode *arrayToList(int arr[], int n)
{
    ListNode *root = NULL;
    for (int i = 0; i < n; i++)
        insert(&root, arr[i]);
   return root;
}
    void insert(ListNode** root, int item)
{
    ListNode* temp = new ListNode;
    ListNode* ptr;
    temp->val = item;
    temp->next = NULL;
  
    if (*root == NULL)
        *root = temp;
    else {
        ptr = *root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}
    ListNode* partition(ListNode* head, int x) {
        int n=0,m=0;
        ListNode* dummy=head;
        int a[201],b[201];
        while(dummy!=NULL)
        {
            if(dummy->val <x){
                a[n]=dummy->val; n++;}
            else
            { b[m]=dummy->val;m++;}
            dummy=dummy->next;
        }
        for(int i=n,j=0;i<n+m;++i,j++)
            a[i]=b[j];
        int size=n+m;
        ListNode* root=arrayToList(a,size);
        
            return root;
    }
};