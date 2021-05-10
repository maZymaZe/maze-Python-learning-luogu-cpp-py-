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
    vector<int> t1, t2;
    void dfs(TreeNode* root,vector<int>&t){
        if(!root)return;
        if(root->left)dfs(root->left,t);
        if(root->right)dfs(root->right,t);
        if(!root->left && !root->right)t.push_back(root->val);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1,t1),dfs(root2,t2);
        if(t1.size()!=t2.size())return false;
        
        int l=t1.size();
        for(int i=0; i<l;i++)if(t1[i]!=t2[i])return false;
        return true;
    }
};