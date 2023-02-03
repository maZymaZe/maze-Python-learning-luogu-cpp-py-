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
    vector<vector<int>> edge;
    vector<int> cnt;
    void dfst(TreeNode* x, TreeNode* fa) {
        if (!x)
            return;
        if (fa) {
            edge[x->val].push_back(fa->val);
        }
        if (x->right) {
            edge[x->val].push_back(x->right->val);
            dfst(x->right, x);
        }
        if (x->left) {
            edge[x->val].push_back(x->left->val);
            dfst(x->left, x);
        }
    }
    void dfs(int x, int fa) {
        cnt.back()++;
        for (auto it : edge[x]) {
            if (it == fa)
                continue;
            dfs(it, x);
        }
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        edge.resize(n + 1);
        dfst(root, 0);
        for (auto it : edge[x]) {
            cnt.push_back(0);
            dfs(it, x);
        }
        int mi = 0;
        for (auto it : cnt)
            mi = max(mi, it);
        return mi > n - mi;
    }
};