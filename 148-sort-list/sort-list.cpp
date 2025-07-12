class Solution {
    private:
        ListNode* mergeList(ListNode* list1, ListNode* list2){  //sort two list
            //only single element in first list
            if(list1->next == NULL){
                list1->next=list2;
                return list1;
            }

            //initialization
            ListNode* curr1=list1;
            ListNode* next1=curr1->next;
            ListNode* curr2=list2;
            ListNode* next2=NULL;

            while(next1 != NULL && curr2 != NULL){
                if((curr2->val >= curr1->val)&&(curr2->val <= next1->val)){
                    //insert curr2 in between curr1 and next1
                    curr1->next=curr2;
                    next2=curr2->next;
                    curr2->next=next1;
                     // Move curr1 and curr2 forward
                    curr1=curr2;
                    curr2=next2;
                }
                else{
                    //move forword list1
                    curr1=next1;
                    next1=next1->next;

                    if(next1 == NULL){     // If we reached end of list1, attach remaining list2
                        curr1->next=curr2;
                        return list1;
                    }
                }
            }
            return list1;
        }

    public:
        ListNode* sortList(ListNode* head) {
            if(head ==NULL || head->next==NULL){
                return head;
            }
            ListNode* temp=NULL;
            ListNode* slow=head;
            ListNode* fast=head;
            // finding middle node and devide in two parts list1 & list2
            while(fast != NULL && fast->next != NULL){
                temp=slow;
                slow=slow->next;
                fast=fast->next->next;
            }
            temp->next=NULL;      // Break the list into two parts

            // Recursively sort both halves
            ListNode* list1=sortList(head);
            ListNode* list2=sortList(slow);

           if(list1->val <= list2->val){
            return mergeList(list1,list2);
           }
           else{
            return mergeList(list2,list1);
           }
        }
};