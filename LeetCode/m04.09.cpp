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
    vector<int> path;
    vector<vector<int>> ans;

    vector<vector<int>> BSTSequences(TreeNode* root) {
        if (!root)
            return {{}};
        deque<TreeNode*> dq;
        dq.push_back(root);
        dfs(dq);
        return ans;
    }
    void dfs(deque<TreeNode*>& dq) {
        if (dq.empty()) {
            ans.push_back(path);
            return;
        }
        int sz = dq.size();
        for (int i = 0; i < sz; i++) {
            TreeNode* node = dq.front();
            dq.pop_front();
            path.push_back(node->val);
            if (node->left)
                dq.push_back(node->left);
            if (node->right)
                dq.push_back(node->right);

            dfs(dq);
            if (node->left)
                dq.pop_back();
            if (node->right)
                dq.pop_back();
            dq.push_back(node);
            path.pop_back();
        }
    }
};