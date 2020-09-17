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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        queue<pair<unsigned long long, TreeNode*>> q;
        unsigned long long ans = 0;
        q.push({1, root});
        while (!q.empty()) {
            int sz = q.size();
            ans = max(q.back().first - q.front().first + 1, ans);
            while (sz > 0) {
                TreeNode* node = q.front().second;
                unsigned long long bf = q.front().first;
                q.pop();
                if (node->left)
                    q.push({2 * bf, node->left});
                if (node->right)
                    q.push({2 * bf + 1, node->right});
                sz--;
            }
        }
        return ans;
    }
};