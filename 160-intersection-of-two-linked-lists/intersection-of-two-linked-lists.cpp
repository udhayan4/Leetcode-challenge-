class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;

        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB) {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }

        return pA; // Either intersection node or nullptr
    }
};