/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void dfs(TreeNode* root,int f,vector<vector<int> >& ans){
    if(root){
        if(ans.size()<=f){
            ans.push_back(vector<int>());
        }
        ans[f].push_back(root->val);
        dfs(root->left,f+1,ans);
        dfs(root->right,f+1,ans);
    }
}
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        dfs(root,0,ans);
        return ans;
    }
};