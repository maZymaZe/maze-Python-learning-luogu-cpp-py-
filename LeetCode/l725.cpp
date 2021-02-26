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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        auto p=root;
        int cnt=0;
        while(p)p=p->next,cnt++;
        int a=cnt%k,b=cnt/k;
        vector<ListNode*> ans;
        p=root;
        for(int i=0;i<a;i++){
            ans.push_back(p);
            for(int j=0;j<b;j++)p=p->next;
            if(p==nullptr)continue;
            auto t=p->next;
            p->next = nullptr;
            p=t;
        }
        k-=a;b--;
        for(int i=0;i<k; i++){
            ans.push_back(p);
            for(int j=0;j<b;j++)p=p->next;
            if(p==nullptr)continue;
            auto t=p->next;
            p->next = nullptr;
            p=t;
        }
        return ans;
    }
};