/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
   public:
    Node* fh;
    Node* flatten(Node* head) {
        if (!head)
            return nullptr;
        fh = new Node(-1, 0, 0, 0);
        fh->next = head;
        dfs(fh, head);
        fh->next->prev = nullptr;
        return fh->next;
    }
    Node* dfs(Node* pre, Node* x) {
        if (!x)
            return pre;
        pre->next = x;
        x->prev = pre;
        Node* nh = x->next;
        Node* t = dfs(x, x->child);
        x->child = nullptr;
        return dfs(t, nh);
    }
};