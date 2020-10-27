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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;
        stack<TreeNode*> s;
        TreeNode* node=root;
        while(!s.empty()||node!=nullptr){
            while(node){
                ans.push_back(node->val);
                s.push(node);
                node=node->left;
            }
            node=s.top();
            s.pop();
            node=node->right;
        }
        return ans;
    }
};