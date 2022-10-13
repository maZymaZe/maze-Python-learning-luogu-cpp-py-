/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s;
        for (int i : nums)
            s.insert(i);
        int pre = -1, n, ans = 0;
        while (head) {
            if (!s.count(pre) && s.count(head->val))
                ans++;
            pre = head->val;
            head = head->next;
        }
        return ans;
    }
};