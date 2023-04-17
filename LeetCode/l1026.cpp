class Solution {
   public:
    int dfs(TreeNode* root, int mi, int ma) {
        if (root == nullptr) {
            return 0;
        }
        int diff = max(abs(root->val - mi), abs(root->val - ma));
        mi = min(mi, root->val);
        ma = max(ma, root->val);
        diff = max(diff, dfs(root->left, mi, ma));
        diff = max(diff, dfs(root->right, mi, ma));
        return diff;
    }

    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};
