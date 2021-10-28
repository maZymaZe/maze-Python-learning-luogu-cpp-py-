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
    int ans = 0;
    long long ps, tx;
    unordered_map<long long, int> mp;
    void dfs(TreeNode* x) {
        if (!x)
            return;
        ps += x->val;
        if (mp.count(ps - tx))
            ans += mp[ps - tx];
        mp[ps]++;
        dfs(x->left);
        dfs(x->right);
        if (mp[ps] == 1)
            mp.erase(ps);
        else
            mp[ps]--;
        ps -= x->val;
    }
    int pathSum(TreeNode* root, int sum) {
        tx = sum;
        ps = 0;
        mp[0] = 1;
        dfs(root);
        return ans;
    }
};