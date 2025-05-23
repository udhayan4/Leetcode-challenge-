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
    ListNode* rotateRight(ListNode* head, int k) {
        int count=0;
        ListNode *p=head;
        ListNode *last;
        if(head==NULL||head->next==NULL){
            return head;
        }
        while(p->next!=NULL){
            count++;
            p=p->next;
        }
        last=p;
        count++;
        p=head;
        k=k%count;
        count=(count-k);
        while(count>1){
            count--;
            p=p->next;
        }
        last->next=head;
        head=p->next;
        p->next=NULL;
        return head;
    }
};