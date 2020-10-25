/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    vector<ListNode*> ans;
    vector<ListNode*> eoi;
    int md = 0;
    void dfs(TreeNode* root, int d) {
        if (!root)
            return;
        if (d > md) {
            md = d;
            ListNode* p = new ListNode(root->val);
            ans.push_back(p);
            eoi.push_back(p);
        } else {
            ListNode* p = new ListNode(root->val);
            eoi[d - 1]->next = p;
            eoi[d - 1] = p;
        }
        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
    }
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        dfs(tree, 1);
        return ans;
    }
};