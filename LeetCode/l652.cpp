/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    int now = 0;
    map<pair<pair<int, int>, int>, int> mp, tp;
    vector<TreeNode*> ans;
    int findtype(TreeNode* root) {
        if (!root)
            return 0;
        int lt = findtype(root->left);
        int rt = findtype(root->right);
        if (mp.count(make_pair(make_pair(lt, rt), root->val))) {
            if (mp[make_pair(make_pair(lt, rt), root->val)] == 1) {
                mp[make_pair(make_pair(lt, rt), root->val)] = 2;
                ans.push_back(root);
            }
        } else {
            mp[make_pair(make_pair(lt, rt), root->val)] = 1;
        }

        if (tp.count(make_pair(make_pair(lt, rt), root->val))) {
            return tp[make_pair(make_pair(lt, rt), root->val)];
        }

        now++;
        tp[make_pair(make_pair(lt, rt), root->val)] = now;

        return now;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        findtype(root);
        return ans;
    }
};