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
    void dfs(TreeNode* root) {
        if (!root)
            return;
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }
    TreeNode* build(vector<int>& t, int l, int r) {
        if (l >= r)
            return nullptr;
        if (l == r - 1)
            return new TreeNode(t[l]);
        int p = l;
        for (int i = l; i < r; i++) {
            if (t[i] > t[p]) {
                p = i;
            }
        }
        return new TreeNode(t[p], build(t, l, p), build(t, p + 1, r));
    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        dfs(root);
        v.push_back(val);
        return build(v, 0, v.size());
    }
};