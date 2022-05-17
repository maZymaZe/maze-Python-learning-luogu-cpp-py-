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
    void dfs(TreeNode* r, vector<int>& x) {
        if (!r)
            return;
        dfs(r->left, x);
        x.push_back(r->val);
        dfs(r->right, x);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> x, y, z;
        dfs(root1, x);
        dfs(root2, y);
        int lx = x.size(), ly = y.size(), px = 0, py = 0;
        while (px < lx && py < ly) {
            if (x[px] < y[py]) {
                z.push_back(x[px]);
                px++;
            } else {
                z.push_back(y[py]);
                py++;
            }
        }
        for (int i = px; i < lx; i++)
            z.push_back(x[i]);
        for (int i = py; i < ly; i++)
            z.push_back(y[i]);
        return z;
    }
};