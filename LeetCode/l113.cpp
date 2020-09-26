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
    vector<vector<int>> ret;
    vector<int> tmp;
    void dfs(TreeNode* root,int sum){
        
        if(root){
            tmp.push_back(root->val);
            if(root->val==sum&&(!root->left)&&(!root->right))ret.push_back(tmp);
            dfs(root->left,sum-root->val);
            dfs(root->right,sum-root->val);
            tmp.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root,sum);
        return ret;
    }
};