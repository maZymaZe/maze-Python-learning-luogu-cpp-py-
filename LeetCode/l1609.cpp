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
    vector<vector<int>> v;
    void dfs(TreeNode* root, int x) {
        if (!root)
            return;
        if (v.size() == x)
            v.push_back(vector<int>());
        v[x].push_back(root->val);
        dfs(root->left, x + 1), dfs(root->right, x + 1);
    }
    bool isEvenOddTree(TreeNode* root) {
        dfs(root, 0);
        int l = v.size();
        for (int i = 0; i < l; i++) {
            if (i & 1) {
                int n = v[i].size();
                for (int j = 0; j < n; j++) {
                    if (v[i][j] & 1)
                        return false;
                    if (j > 0 && v[i][j] >= v[i][j - 1])
                        return false;
                }
            } else {
                int n = v[i].size();
                for (int j = 0; j < n; j++) {
                    if ((v[i][j] & 1) == 0)
                        return false;
                    if (j > 0 && v[i][j] <= v[i][j - 1])
                        return false;
                }
            }
        }
        return true;
    }
};