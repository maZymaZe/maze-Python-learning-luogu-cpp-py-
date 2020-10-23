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
    int cnt = 0;
    ListNode* fmid(ListNode* head) {
        ListNode *f = head, *s = head;
        while (f) {
            if (!f->next) {
                cnt++;
                break;
            }
            f = f->next, cnt++;
            s = s->next;
            if (f)
                f = f->next, cnt++;
        }
        return s;
    }
    ListNode* rev(ListNode* head) {
        ListNode *pre = nullptr, *p = head, *t;
        while (p) {
            t = p->next;
            p->next = pre;
            pre = p;
            p = t;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if (!head)
            return true;
        ListNode* mid = fmid(head);
        mid = rev(mid);
        if (cnt % 2 == 1) {
            cnt /= 2;
            ListNode *p1 = head, *p2 = mid;
            for (int i = 1; i <= cnt; i++) {
                if (p1->val != p2->val)
                    return false;
                p1 = p1->next, p2 = p2->next;
            }
        } else {
            cnt /= 2;
            ListNode *p1 = head, *p2 = mid;
            for (int i = 1; i <= cnt; i++) {
                if (p1->val != p2->val)
                    return false;
                p1 = p1->next, p2 = p2->next;
            }
        }
        return true;
    }
};