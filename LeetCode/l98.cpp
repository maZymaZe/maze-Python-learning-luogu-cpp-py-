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
struct RTPK {
    int mx, mi, vld;
};
class Solution {
   public:
    RTPK ck(TreeNode* root) {
        int mx = root->val, mi = root->val, vld = 1;
        RTPK lrt, rrt;
        if (root->left) {
            lrt = ck(root->left);
            vld &= lrt.vld;
            if (root->val <= lrt.mx)
                vld = 0;
            mi = lrt.mi;
        }
        if (root->right) {
            rrt = ck(root->right);
            vld &= rrt.vld;
            if (root->val >= rrt.mi)
                vld = 0;
            mx = rrt.mx;
        }
        return {mx, mi, vld};
    }
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        return ck(root).vld;
    }
};