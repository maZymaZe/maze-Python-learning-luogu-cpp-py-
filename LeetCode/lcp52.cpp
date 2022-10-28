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
    set<int> s;
    void dfs(TreeNode* root) {
        if (!root)
            return;
        s.insert(root->val);
        dfs(root->left), dfs(root->right);
    }
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        dfs(root);
        int l = ops.size();
        int c[2] = {0};
        for (int i = l - 1; i >= 0; i--) {
            auto it = s.lower_bound(ops[i][1]);
            while (it != s.end() && *it <= ops[i][2]) {
                c[ops[i][0]]++;
                it = s.erase(it);
            }
        }
        return c[1];
    }
};