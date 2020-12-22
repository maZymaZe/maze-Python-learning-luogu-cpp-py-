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
    vector<vector<int>> ans;
    void dfs(TreeNode* root,int d){
        if(!root)return;
        if(d>=ans.size()){
            ans.push_back({root->val});
        }else ans[d].push_back({root->val});
        dfs(root->left,d+1);
        dfs(root->right,d+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root,0);
        for(int i=1;i<ans.size();i+=2)reverse(ans[i].begin(),ans[i].end());
        return ans;
    }
};