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
    int ans=0;
    int dfs(TreeNode* root){
        if(!root)return 1;
        int l=dfs(root->left);
        int r=dfs(root->right);
        if(l==2||r==2){
            ans++;
            return 0;
        }
        else if(l==0||r==0)return 1;
        return 2;
    }
    int minCameraCover(TreeNode* root) {
        if(!root)return 0;
        if(dfs(root)==2)ans++;
        return ans;
    }
};