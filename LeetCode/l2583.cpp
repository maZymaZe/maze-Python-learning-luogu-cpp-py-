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
    vector<long long> v;
    void dfs(TreeNode* rt, int d) {
        if (!rt)
            return;
        if (d >= v.size())
            v.push_back(rt->val);
        else
            v[d] += rt->val;
        dfs(rt->left, d + 1), dfs(rt->right, d + 1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        dfs(root, 0);
        if (v.size() < k)
            return -1;
        nth_element(v.begin(), v.end() - k, v.end());
        return *(v.end() - k);
    }
};