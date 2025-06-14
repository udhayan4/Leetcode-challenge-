class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) 
            return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if (root->left == NULL || root->right == NULL)
            return max(left, right) + 1;

        return min(left, right) + 1;
    }
};