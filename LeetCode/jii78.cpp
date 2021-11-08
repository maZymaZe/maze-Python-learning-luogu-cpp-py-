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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> rs;
        int l = lists.size();
        for (int i = 0; i < l; i++) {
            auto p = lists[i];
            while (p)
                rs.push_back(p->val), p = p->next;
        }
        sort(rs.begin(), rs.end());
        ListNode* ans = new ListNode();
        if (rs.size() == 0)
            return nullptr;
        l = rs.size();
        auto p = ans;
        for (int i = 0; i < l; i++) {
            p->next = new ListNode(rs[i]);
            p = p->next;
        }
        return ans->next;
    }
};