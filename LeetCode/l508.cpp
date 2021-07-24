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
    unordered_map<long long, int> mp;
    int mx = 0;

    long long dfs(TreeNode* root) {
        if (!root)
            return 0;
        long long ret = root->val;
        if (root->left)
            ret += dfs(root->left);
        if (root->right)
            ret += dfs(root->right);
        mx = max(mx, ++mp[ret]);
        return ret;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        mx = 0;
        dfs(root);
        vector<int> answer;
        for (auto i : mp) {
            if (i.second == mx)
                answer.push_back((int)i.first);
        }
        return answer;
    }
};