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
struct st {
    int t, s;
    bool operator<(const st& x) const { return s == x.s ? t < x.t : s < x.s; }
};
class Solution {
   public:
    vector<vector<int>> ans;
    map<st, vector<int>> mp;
    void dfs(TreeNode* root, int x, int y) {
        if (!root)
            return;
        mp[{x, y}].push_back(root->val);
        dfs(root->left, x + 1, y - 1);
        dfs(root->right, x + 1, y + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        int pre = 2;
        for (auto& i : mp) {
            if (pre != i.first.s) {
                ans.push_back(vector<int>());
            }
            sort(i.second.begin(), i.second.end());
            for (auto& j : i.second)
                ans.back().push_back(j);
            pre = i.first.s;
        }
        return ans;
    }
};