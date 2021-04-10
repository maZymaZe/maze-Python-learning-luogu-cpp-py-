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
    TreeNode* myfunc(vector<int>& nums,int l,int r){
        if(l>r)return nullptr;
        if(l==r){
            return new TreeNode(nums[l]);
        }
        int mid=(l+r)/2;
        TreeNode* rt=new TreeNode(nums[mid]);
        rt->left=myfunc(nums,l,mid-1);
        rt->right=myfunc(nums,mid+1,r);
        return rt;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return myfunc(nums,0,nums.size()-1);
    }
};