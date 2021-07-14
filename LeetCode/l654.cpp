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
    int findmax(vector<int>&nums,int a,int b){
       int ma=nums[a],mp=a;
       for(int i=a;i<=b;i++){
           if(nums[i]>ma){
               ma=nums[i];
               mp=i;
           }
       } 
       return mp;
    }
    TreeNode* job(vector<int>& nums,int l,int r){
        if(l==r)return new TreeNode(nums[l]);
        if(l>r)return nullptr;
        int m=findmax(nums,l,r);
        TreeNode* ret=new TreeNode(nums[m],job(nums,l,m-1),job(nums,m+1,r));
        return ret;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return job(nums,0,nums.size()-1);
    }
};