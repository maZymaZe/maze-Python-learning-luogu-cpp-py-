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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        //s.push(root);
        TreeNode* now=root;
        while(now!=NULL||!s.empty()){
           
            while(now!=NULL){
                s.push(now);
                now=now->left;
            } 
            
            now=s.top();
           s.pop();
            ans.push_back((now->val));
            now=now->right;
        }
        return ans;
    }
};