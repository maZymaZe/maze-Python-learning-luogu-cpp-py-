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
int dfs(TreeNode *root,TreeNode *fa){
    if(!root)return 0;
    int t1=dfs(root->left,root);
    if(t1==0)root->left=nullptr;
    int t2=dfs(root->right,root);
    if(t2==0)root->right=nullptr;
    return root->val+t1+t2;
}
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)return nullptr;
        int t3=dfs(root,nullptr);
        if(t3)return root;
        return nullptr; 
    }
};