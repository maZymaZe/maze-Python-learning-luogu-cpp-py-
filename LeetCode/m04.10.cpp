class Solution {
   private:
    string in_order(TreeNode* root) {
        if (root == nullptr) {
            return "#";
        }
        string l = in_order(root->left);
        string r = in_order(root->right);
        return l + " " + to_string(root->val) + " " + r;
    }

   public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        string str1 = in_order(t1), str2 = in_order(t2);
        return str1.find(str2) != string::npos;
    }
};