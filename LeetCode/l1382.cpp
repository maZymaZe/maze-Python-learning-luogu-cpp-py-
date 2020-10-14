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
    int l;
    vector<int> s;
    void dfs(TreeNode* root){
        if(!root)return;
        dfs(root->left);
        s.push_back(root->val);
        dfs(root->right);
    }
    TreeNode* build(int l,int r){
        if(l>=r)return NULL;
        int mid=(l+r)/2;
        TreeNode *root=new TreeNode(s[mid]);
        root->left=build(l,mid);
        root->right=build(mid+1,r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        s.clear();
        dfs(root);
        l=s.size();
        TreeNode* ret=build(0,l);
        return ret;
    }
};