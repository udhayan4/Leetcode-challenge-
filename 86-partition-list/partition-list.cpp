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
    ListNode* partition(ListNode* head, int x) {
         ListNode *ptr1=NULL,*ptr2=NULL,*current1=NULL,*current2=NULL;
         if(head==NULL) return head;
         while(head){
             ListNode *tem = new ListNode(head->val);
             tem->val=head->val;
             tem->next=NULL;
             if(head->val<x){
                 if(ptr1==NULL){
                     ptr1=tem;
                     current1=tem;
                 }
                 else{
                     current1->next=tem;
                     current1=current1->next;
                 }
             }
             else{
                 if(ptr2==NULL){
                    ptr2=tem;
                    current2=tem;
                 }
                 else{
                     current2->next=tem;
                     current2=current2->next;
                 }
             }
             head=head->next;
         }
         ListNode *head1=ptr1;
         if(ptr1==NULL){
            ptr1=ptr2;
            return ptr1;
         }
         while(ptr1->next!=NULL){
             ptr1=ptr1->next;
         }
         ptr1->next=ptr2;
         return head1;
    }
};