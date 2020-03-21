/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL)return 0;
        int mod=root->val%1000000007;
        if(root->left==NULL&&root->right==NULL)return mod;
        if(root->left!=NULL)root->left->val+=mod<<1;
        if(root->right!=NULL)root->right->val+=mod<<1;
        return (sumRootToLeaf(root->left)+sumRootToLeaf(root->right))%1000000007;
    }
};