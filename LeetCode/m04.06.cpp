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
    TreeNode *ans, *pp;
    int flag = 0;
    void dfs(TreeNode* root) {
        if (!root)
            return;
        dfs(root->left);
        if (flag == 1)
            ans = root, flag = 2;
        if (root == pp)
            flag = 1;
        dfs(root->right);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        pp = p;
        dfs(root);
        if (flag == 2)
            return ans;
        return nullptr;
    }
};