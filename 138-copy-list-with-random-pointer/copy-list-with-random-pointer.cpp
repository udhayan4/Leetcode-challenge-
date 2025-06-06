/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* helper(Node* head, unordered_map<Node*, Node*>&mp){
        if(head == 0) return 0;

        Node* newHead = new Node(head->val);
        // mapped old node to new node
        mp[head] = newHead;
        newHead->next = helper(head->next, mp);

        // if random pointer of head exist, then do this 
        // i.e. map new head random pointer to another newly created node using map
        if(head->random){
            newHead->random = mp[head->random];
        }
        return newHead;
    }

    Node* helper2(Node* head){
        if(!head) return 0;

        // Step1: Clone A -> A' (I.e. old node to new node)
        Node* it = head; // iterate over old node
        while(it){
            Node* cloneNode = new Node(it->val);
            cloneNode->next = it->next;
            it->next = cloneNode;
            it = it->next->next;
        }

        // Step2: Assign random links of A' with the helper of A
        it = head;
        while(it){
            Node* cloneNode = it->next;
            cloneNode->random = it->random ? it->random->next : nullptr;
            it = it->next->next;
        }

        // Step3: Detach A' from A
        it = head;
        Node* cloneHead = it->next;
        while(it){
            Node* cloneNode = it->next;
            it->next = it->next->next;
            if(cloneNode->next){
                cloneNode->next = cloneNode->next->next;
            }
            it = it->next;
        }
        return cloneHead;
    }

    Node* copyRandomList(Node* head) {

        // // APPROACH-1: - Using Map - S.C. O(n)
        // unordered_map<Node*, Node*> mp; // old node --> new node
        // return helper(head, mp);

        // APPROACH-2: - Without Map - S.C. O(1)
        return helper2(head);
    }
};