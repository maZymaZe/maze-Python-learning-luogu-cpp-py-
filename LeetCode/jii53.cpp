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
    TreeNode *a, *b;
    int v = 0;
    void dfs(TreeNode* root) {
        if (!root)
            return;
        dfs(root->left);
        if (v && b == 0)
            b = root;
        if (root == a)
            v = 1;
        dfs(root->right);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        a = p, b = 0;
        dfs(root);
        return b;
    }
};