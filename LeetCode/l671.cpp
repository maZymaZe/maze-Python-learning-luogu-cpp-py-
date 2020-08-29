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
    int min1,min2;
    int fmi(TreeNode* root){
        if(!root)return -1;
        if(root->val!=min1)return root->val;
        int t1=fmi(root->left),t2=fmi(root->right);
        int ret=-1;
        if(t1>0)ret=t1;
        if(t2>0){
            if(ret>0)ret=min(ret,t2);
            else ret=t2;
        }
        return ret;
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)return -1;
        min1=root->val;
        min2=-1;
        int l=fmi(root->left);
        if(l>0)min2=l;
        int r=fmi(root->right);
        if(r>0){
            if(min2>0)min2=min(min2,r);
            else min2=r;
        }
        return min2;
    }
};