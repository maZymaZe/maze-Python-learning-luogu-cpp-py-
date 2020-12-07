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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A||!B)return false;
        if(A->val==B->val&&ck(A,B))return true;
        return isSubStructure(A->left,B)||isSubStructure(A->right,B);
    }
    bool ck(TreeNode* A, TreeNode* B) {
        if(!B)return true;
        if(!A)return false;
        if(A->val!=B->val)return false;
        return ck(A->left,B->left)&&ck(A->right,B->right);
    }
};