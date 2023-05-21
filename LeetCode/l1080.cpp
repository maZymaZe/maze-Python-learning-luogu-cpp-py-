class Solution {
   public:
    bool checkSufficientLeaf(TreeNode* node, int sum, int limit) {
        if (!node) {
            return false;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return node->val + sum >= limit;
        }
        bool haveSufficientLeft =
            checkSufficientLeaf(node->left, sum + node->val, limit);
        bool haveSufficientRight =
            checkSufficientLeaf(node->right, sum + node->val, limit);
        if (!haveSufficientLeft) {
            node->left = nullptr;
        }
        if (!haveSufficientRight) {
            node->right = nullptr;
        }
        return haveSufficientLeft || haveSufficientRight;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        bool haveSufficient = checkSufficientLeaf(root, 0, limit);
        return haveSufficient ? root : nullptr;
    }
};
