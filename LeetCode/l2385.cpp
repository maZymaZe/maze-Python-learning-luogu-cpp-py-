/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    vector<TreeNode*> fa;
    TreeNode* sta;
    int ans, star;
    void ffa(TreeNode* rt, TreeNode* f) {
        if (!rt)
            return;
        int x = rt->val;
        if (rt->val == star)
            sta = rt;
        if (fa.size() <= x)
            fa.resize(x + 1);
        fa[x] = f;
        ffa(rt->left, rt);
        ffa(rt->right, rt);
    }
    void dfs(TreeNode* cur, TreeNode* fro, int t) {
        if (!cur)
            return;
        ans = max(ans, t);
        if (fro != cur->left)
            dfs(cur->left, cur, t + 1);
        if (fro != cur->right)
            dfs(cur->right, cur, t + 1);
        if (fro != fa[cur->val])
            dfs(fa[cur->val], cur, t + 1);
    }
    int amountOfTime(TreeNode* root, int start) {
        ans = 0, star = start;
        ffa(root, 0);
        dfs(sta, 0, 0);
        return ans;
    }
};