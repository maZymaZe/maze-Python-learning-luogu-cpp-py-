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
    int closestValue(TreeNode* root, double target) {
        double mi = 1e18, eps = 1e-6;
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val;
        if (fabs(target - root->val) < eps)
            return root->val;
        if (root->val > target + eps) {
            if (root->left) {
                int ll = closestValue(root->left, target);
                if (fabs(target - ll) < fabs(target - root->val))
                    return ll;
                else
                    return root->val;
            }
            return root->val;
        }
        if (root->val < target - eps) {
            if (root->right) {
                int ll = closestValue(root->right, target);
                if (fabs(target - ll) < fabs(target - root->val))
                    return ll;
                else
                    return root->val;
            }
            return root->val;
        }
        return -1;
    }
};