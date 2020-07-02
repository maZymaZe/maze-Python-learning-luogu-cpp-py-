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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int r=nums.size();
        return res(nums,0,r-1);
    }
    TreeNode* res(vector<int>& nums,int l,int r){
        if(r<l)return NULL;
        else if(l==r){
            TreeNode* p=new TreeNode(nums[l]);
            return p;
        }
        else{
            int mid=(l+r+1)/2;
            TreeNode* p=new TreeNode(nums[mid]);
            p->left=res(nums,l,mid-1);
            p->right=res(nums,mid+1,r);
            return p;
        }
        return NULL;
    }
};