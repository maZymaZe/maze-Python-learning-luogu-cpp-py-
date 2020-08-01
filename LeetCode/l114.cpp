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
    void flatten(TreeNode* root) {
        if(!root)return;
        TreeNode *t=root->left;
        if(root->left){
            flatten(root->left);
            while(t->right)t=t->right;
        
            if(root->right){
                flatten(root->right);
            }
            if(t)t->right=root->right;
            root->right=root->left;
            root->left=NULL;
            return;
        }else{
            if(root->right){
                flatten(root->right);
            }
            return;
        }
    }
};