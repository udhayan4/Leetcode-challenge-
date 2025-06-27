/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findPathSums(TreeNode* root,int& target, int& curSum, vector<int>& current,vector<vector<int>>& res){
        if(!root)return;

        curSum += root->val;
        current.push_back(root->val);

        if(!root->left && !root->right && target == curSum){
            res.push_back(current);
        }

        findPathSums(root->left,target, curSum, current, res);
        findPathSums(root->right,target, curSum, current, res);
        curSum -= root->val;
        current.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp; 
        int currentSum = 0;
        findPathSums(root,targetSum,currentSum,temp,res);
        return res;
    }
};