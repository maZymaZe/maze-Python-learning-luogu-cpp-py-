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
    vector<int> v;
    void dfs(TreeNode* rt) {
        if (!rt)
            return;
        dfs(rt->left);
        v.push_back(rt->val);
        dfs(rt->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        dfs(root);
        for (int i : queries) {
            vector<int> t;
            auto it = upper_bound(v.begin(), v.end(), i);
            if (it == v.begin()) {
                t.push_back(-1);
            } else {
                --it;
                t.push_back(*it);
            }
            it = lower_bound(v.begin(), v.end(), i);
            if (it == v.end()) {
                t.push_back(-1);
            } else {
                t.push_back(*it);
            }
            ans.push_back(t);
        }
        return ans;
    }
};