struct NODE {
    NODE *l, *r;
    int val;
    NODE() { l = nullptr, r = nullptr, val = 0; }
    NODE(int val) { l = nullptr, r = nullptr, val = val; }
    NODE(NODE* ll, NODE* rr, int vval) {
        l = ll;
        r = rr;
        val = vval;
    }
};
class MyLinkedList {
   public:
    int sz;
    NODE *hd, *end;
    MyLinkedList() {
        sz = 0;
        hd = new NODE();
        end = hd;
    }

    int get(int index) {
        if (index >= sz)
            return -1;
        NODE* p = hd->r;
        while (index--) {
            p = p->r;
        }
        return p->val;
    }

    void addAtHead(int val) {
        NODE* nh = new NODE(hd, hd->r, val);
        nh->val = val;
        if (hd->r)
            hd->r->l = nh;
        hd->r = nh;
        sz++;
        if (sz == 1)
            end = nh;
    }

    void addAtTail(int val) {
        NODE* nh = new NODE(end, nullptr, val);
        nh->val = val;
        end->r = nh;
        end = nh;
        sz++;
    }

    void addAtIndex(int index, int val) {
        if (index == sz)
            addAtTail(val);
        else if (index <= 0)
            addAtHead(val);
        else if (index > sz) {
        } else {
            NODE *p = hd, *q = hd->r;
            for (int i = 0; i < index; i++) {
                p = p->r, q = q->r;
            }
            NODE* nh = new NODE(p, q, val);
            p->r = nh;
            q->l = nh;
            sz++;
        }
    }

    void deleteAtIndex(int index) {
        if (index >= 0 && index < sz) {
            NODE* p = hd->r;
            for (int i = 0; i < index; i++) {
                p = p->r;
            }
            NODE *ll = p->l, *rr = p->r;
            if (ll)
                ll->r = rr;
            if (rr)
                rr->l = ll;
            if (index == sz - 1) {
                end = ll;
            }
            sz--;
            delete p;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main() {
    auto x = MyLinkedList();
    x.addAtHead(1);
    x.addAtTail(3);
    x.addAtIndex(1, 2);
    x.get(1);
    x.deleteAtIndex(1);
    x.get(1);
    return 0;
}