class Solution {
public:
    void post(TreeNode* root, vector<int>& result) {
        if (!root) return;                // \U0001f9f1 Base: null node

        post(root->left, result);         // ⬅️ Visit left subtree
        post(root->right, result);        // ➡️ Visit right subtree
        result.push_back(root->val);      // ⬆️ Visit root node
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        post(root, result);               // \U0001f501 DFS helper
        return result;
    }
};