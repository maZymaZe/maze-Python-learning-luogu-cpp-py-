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
    int hi(TreeNode* root) {
        return root == nullptr ? 0 : (1 + max(hi(root->left), hi(root->right)));
    }
    void dfs(vector<vector<string>>& res, TreeNode* cur, int i, int l, int r) {
        if (cur) {
            res[i][(l + r) >> 1] = to_string(cur->val);
            dfs(res, cur->left, i + 1, l, (l + r) >> 1);
            dfs(res, cur->right, i + 1, (l + r + 1) >> 1, r);
        }
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = hi(root);
        int wid = (1 << h) - 1;
        vector<vector<string>> res(h, vector<string>(wid, ""));
        dfs(res, root, 0, 0, wid);
        return res;
    }
};