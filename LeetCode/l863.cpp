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
    vector<int> ans;
    int K;
    TreeNode* t;
    vector<TreeNode*> st;
    int flag = 0;
    void ddfs(TreeNode* root) {
        if (!root)
            return;
        st.push_back(root);
        if (root == t) {
            flag = 1;
            int l = st.size();
            if (K && l - 1 - K >= 0)
                ans.push_back(st[l - 1 - K]->val);
            for (int i = l - 2; i >= 0; i--) {
                if (st[i]->left == st[i + 1]) {
                    dfs(st[i]->right, K - (l - i));
                } else {
                    dfs(st[i]->left, K - (l - i));
                }
            }
        }
        if (flag)
            return;

        ddfs(root->left);
        if (flag)
            return;
        ddfs(root->right);
        if (flag)
            return;
        st.pop_back();
    }
    void dfs(TreeNode* root, int dep) {
        if (dep < 0)
            return;
        if (!root)
            return;
        dfs(root->left, dep - 1);
        dfs(root->right, dep - 1);
        if (dep == 0)
            ans.push_back(root->val);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        K = k;
        ans.clear();
        t = target;
        dfs(target, k);
        ddfs(root);

        return ans;
    }
};