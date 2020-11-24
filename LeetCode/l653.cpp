/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_set<int> s;
    int K,f=0;
    void dfs(TreeNode* root){
        if(!root)return;
        if(s.count(K-root->val)){f=1;return;}
        s.insert(root->val);
        dfs(root->left),dfs(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        K=k;
        dfs(root);
        return f;
    }
};