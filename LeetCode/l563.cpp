/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */ 
int tot; 
class Solution {
public:
    int findTilt(TreeNode* root) {
        tot=0;
        f(root);
        return tot;

    }
    int f(TreeNode* root){
        if(!root) return 0;
        int l=f(root->left),r=f(root->right);
        tot+=abs(l-r);
        return root->val+l+r;
    }
};