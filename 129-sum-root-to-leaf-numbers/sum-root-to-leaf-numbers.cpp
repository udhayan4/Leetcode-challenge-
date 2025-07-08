class Solution {
public:
    int sumNumbers(TreeNode* root) {
        queue<pair<int, TreeNode*>> q;
        int sol = 0;
        q.push({root->val, root});
        while (!q.empty()) {
            auto [val, temp] = q.front();
            q.pop();
            if (temp->left)
                q.push({val * 10 + temp->left->val, temp->left});
            if (temp->right)
                q.push({val * 10 + temp->right->val, temp->right});
            if (!temp->left && !temp->right)
                sol += val;
        }
        return sol;
    }
};