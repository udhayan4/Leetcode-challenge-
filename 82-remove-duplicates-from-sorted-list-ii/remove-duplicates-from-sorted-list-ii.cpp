class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        // Edge case: handle duplicates at the beginning of the list
        bool edge = false;
        while (head->next && head->val == head->next->val) {
            edge = true;
            head = head->next;
        }
        if (edge) head = head->next;

        // Use three pointers: prev, curr, and fwd
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* fwd = curr ? curr->next : NULL;

        while (curr != NULL && fwd != NULL) {
            bool isChanged = false;

            // Skip all duplicates for current value
            while (fwd && curr->val == fwd->val) {
                isChanged = true;
                fwd = fwd->next;
            }

            if (isChanged) {
                // Duplicates found: remove them
                if (prev) {
                    prev->next = fwd;
                } else {
                    head = fwd;
                }
                curr = fwd;
                if (fwd) fwd = fwd->next;
            } else {
                // No duplicates: move all pointers forward
                prev = curr;
                curr = fwd;
                if (fwd) fwd = fwd->next;
            }
        }

        return head;
    }
};