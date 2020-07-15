#include <cstdio>
const int INF = 0x3f3f3f3f;

#define MAXN 100005
#define trial (val < cur->key ? cur->lst : cur->rst)
struct Node {
    Node *lst, *rst, *pre;
    int key, weight, size;
    bool IsLst() { return this == this->pre->lst; }
    void Pushup() { this->size = lst->size + rst->size + this->weight; }
};
class SplayTree {
   protected:
    Node MemoryPool[MAXN];
    Node *root, *tail, *null;
    Node* bin[MAXN];
    int bintop;
    Node* NewNode(int key) {
        Node* x = bintop ? bin[--bintop] : tail++;
        x->key = key;
        x->weight = x->size = 1;
        x->pre = x->lst = x->rst = null;
        return x;
    }
    void Midorder(Node* cur) {
        if (cur != null && cur->key != -INF && cur->key != INF) {
            Midorder(cur->lst);
            for (int i = 0; i < cur->weight; i++) {
                printf("%d ", cur->key);
            }
            Midorder(cur->rst);
        }
    }
    void Clear(Node* x) {
        if (x != null) {
            Clear(x->lst);
            Clear(x->rst);
            bin[bintop++] = x;
        }
    }
    void Rotate(Node* x) {
        Node *y = x->pre, *z = y->pre;
        bool k = x->IsLst();

        if (y->IsLst())
            z->lst = x;
        else
            z->rst = x;
        x->pre = z;

        if (k)
            y->lst = x->rst, x->rst->pre = y;
        else
            y->rst = x->lst, x->lst->pre = y;

        if (k)
            x->rst = y;
        else
            x->lst = y;
        y->pre = x;

        y->Pushup();
    }
    void Splay(Node* x, Node* ter) {
        while (x->pre != ter) {
            Node* y = x->pre;
            if (y->pre != ter) {
                Rotate((x->IsLst() == y->IsLst()) ? y : x);
            }
            Rotate(x);
        }
        x->Pushup();
        if (ter == null)
            root = x;
    }
    void Search(int val) {
        if (root != null) {
            Node* cur = root;
            while (val != cur->key) {
                Node* Next = trial;
                if (Next == null)
                    break;
                cur = Next;
            }
            Splay(cur, null);
        }
    }

   public:
    SplayTree(void) {
        tail = MemoryPool;
        null = tail++;
        null->lst = null->rst = null;
        null->weight = null->size = null->key = 0;
        root=null;bintop=0;
    }
    void Print_Midorder() {
        Midorder(root);
        printf("\n");
    }
    int Calculate_Rank(int val) {
        Search(val);
        return root->lst->size;
    }
    Node* Rank_Locate(int k) {
        k++;
        Node* cur = root;
        while (true) {
            if (k <= cur->lst->size)
                cur = cur->lst;
            else if (k > cur->lst->size + cur->weight) {
                k -= cur->lst->size + cur->weight;
                cur = cur->rst;
            } else
                return cur;
        }
    }
    Node* Forward(int val) {
        Search(val);
        if (root->key < val) {
            return root;
        }
        Node* cur = root->lst;
        while (cur->rst != null)
            cur = cur->rst;
        return cur;
    }
    Node* Backward(int val) {
        Search(val);
        if (root->key > val) {
            return root;
        }
        Node* cur = root->rst;
        while (cur->lst != null)
            cur = cur->lst;
        return cur;
    }
    void Insert(int val) {
        Node *cur = root, *f = null;
        while (cur != null && val != cur->key) {
            f = cur, cur = trial;
        }
        if (cur != null)
            cur->weight++;
        else {
            cur = NewNode(val);
            if (f != null) {
                ((val > f->key) ? f->rst : f->lst) = cur;
                cur->pre = f;
            }
        }
        Splay(cur, null);
    }
    void Erase_via_value(int val) {
        Node *Last = Forward(val), *Next = Backward(val);
        Splay(Last, null);
        Splay(Next, Last);
        Node* cur = Next->lst;
        if (cur->weight > 1) {
            cur->weight--;
            Splay(cur, null);
        } else {
            Clear(Next->lst);
            Next->lst = null;
        }
    }
};
SplayTree ST;
int main() {
    
    ST.Insert(-INF), ST.Insert(INF);
    int n, t, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &t, &x);
        if (t == 1) {
            ST.Insert(x);
        } else if (t == 2) {
            ST.Erase_via_value(x);
        } else if (t == 3) {
            printf("%d\n", ST.Calculate_Rank(x));
        } else if (t == 4) {
            printf("%d\n", ST.Rank_Locate(x)->key);
        } else if (t == 5) {
            printf("%d\n", ST.Forward(x)->key);
        } else if (t == 6) {
            printf("%d\n", ST.Backward(x)->key);
        }
    }

    return 0;
}