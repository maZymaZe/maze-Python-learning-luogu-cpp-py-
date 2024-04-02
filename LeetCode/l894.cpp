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
    TreeNode* deepcopy(TreeNode* rt) {
        if (!rt)
            return nullptr;
        auto ret = new TreeNode();
        if (rt->left)
            ret->left = deepcopy(rt->left);
        if (rt->right)
            ret->right = deepcopy(rt->right);
        return ret;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> dp(n + 1);
        dp[0].push_back(nullptr);
        dp[1].push_back(new TreeNode());
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j + 1 < i; j++) {
                for (TreeNode* lt : dp[j]) {
                    for (TreeNode* rt : dp[i - 1 - j]) {
                        auto nt = new TreeNode();
                        nt->left = deepcopy(lt);
                        nt->right = deepcopy(rt);
                        dp[i].push_back(nt);
                    }
                }
            }
        }
        return dp[n];
    }
};