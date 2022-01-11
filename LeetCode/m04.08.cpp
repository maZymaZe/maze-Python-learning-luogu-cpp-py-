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
    vector<TreeNode*> pp, qq;
    int f = 0;
    void dfs(TreeNode* root, TreeNode* target, vector<TreeNode*>& r) {
        if (!root)
            return;
        r.push_back(root);
        if (target == root) {
            f = 1;
            return;
        }
        if (!f && root->left)
            dfs(root->left, target, r);
        if (!f && root->right)
            dfs(root->right, target, r);
        if (!f)
            r.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        f = 0;
        dfs(root, p, pp);
        f = 0;
        dfs(root, q, qq);
        int l1 = pp.size(), l2 = qq.size();
        TreeNode* ans = root;
        for (int i = 0; i < l1; i++) {
            if (i == l2)
                break;
            if (pp[i] == qq[i])
                ans = pp[i];
        }
        return ans;
    }
};