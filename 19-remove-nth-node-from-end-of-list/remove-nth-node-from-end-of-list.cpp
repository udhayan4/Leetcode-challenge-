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
        ListNode* slow=head;
        ListNode* fast=head;
        while(n>0){
            fast=fast->next;
            n--;
        }
        if(fast==NULL){
            ListNode* delnode=head;
            head=head->next;
            delete delnode;
            return head;
        }
        while(fast&& fast->next){
            slow=slow->next;
            fast=fast->next;

        }

        ListNode* delnode=slow->next;
        slow->next=delnode->next;
        delete delnode;
        return head;
    }
};