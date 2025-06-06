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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        unordered_map<int,int> mpp;
        int i,n=inorder.size(),m=postorder.size();
        for(i=0;i<n;i++)
        {
            mpp[inorder[i]]=i;
        }
        TreeNode *root=build(inorder,0,n-1,postorder,0,m-1,mpp);
        return root;
    }
    
    TreeNode* build(vector<int>&in,int is,int ie,vector<int>&pos,int ps,int pe,unordered_map<int,int> &mpp)
    {
       if(is>ie || ps>pe)
       return NULL;
       TreeNode* root=new TreeNode(pos[pe]);
       int inroot=mpp[pos[pe]],j=inroot-is;
       root->left=build(in,is,inroot-1,pos,ps,ps+j-1,mpp);
       root->right=build(in,inroot+1,ie,pos,ps+j,pe-1,mpp);
       return root;
    }
};