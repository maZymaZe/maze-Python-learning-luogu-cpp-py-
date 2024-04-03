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
    TreeNode* ans;
    void dfs(TreeNode* o, TreeNode* c, TreeNode* t) {
        if (!o)
            return;
        if (o == t)
            ans = c;
        dfs(o->left, c->left, t);
        dfs(o->right, c->right, t);
    }
    TreeNode* getTargetCopy(TreeNode* original,
                            TreeNode* cloned,
                            TreeNode* target) {
        dfs(original, cloned, target);
        return ans;
    }
};