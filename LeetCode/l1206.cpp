const int MAX_LEVEL = 25;
const int MAXN=3e4+10;
const int INF=0x3f3f3f3f;
struct SkipListNode{
    int Key,Next[MAX_LEVEL+3];
};
class Skiplist {
public:
    int top=0,node_tot=0,head=0,tail=0;
    int st[MAXN]={0};
    SkipListNode lst[MAXN];
    int Size;
    Skiplist() {
        new_node(head, -INF), new_node(tail, INF);
        srand(2652);
        for (int i = 1; i <= MAX_LEVEL; ++i) {
            lst[head].Next[i] = tail;
        }
    }
    bool search(int target) {
        int p = head;
        for (int i = MAX_LEVEL; i; --i) {
            while (lst[p].Next[i] ^ tail && lst[lst[p].Next[i]].Key < target) {
                p = lst[p].Next[i];
            }
        }
        return (lst[lst[p].Next[1]].Key==target);
    }
    
    void add(int num) {
        int p = head, update[MAX_LEVEL + 3];
        int k = rand_level();
        for (int i = MAX_LEVEL; i; --i) {
            while (lst[p].Next[i] ^ tail && lst[lst[p].Next[i]].Key < num) {
                p = lst[p].Next[i];
            }
            update[i] = p;
        }
        int temp;
        new_node(temp, num);
        for (int i = k; i; --i) {
            lst[temp].Next[i] = lst[update[i]].Next[i];
            lst[update[i]].Next[i] = temp;
        }
    }
    int rand_level() {
        int ret = 1;
        while (rand() % 2 && ret < MAX_LEVEL)
            ++ret;
        return ret;
    }
    bool erase(int num) {
        int p = head, update[MAX_LEVEL + 3];
        for (int i = MAX_LEVEL; i; --i) {
            while (lst[p].Next[i] ^ tail && lst[lst[p].Next[i]].Key < num) {
                p = lst[p].Next[i];
            }
            update[i] = p;
        }
        int temp;
        if(lst[lst[p].Next[1]].Key==num){
            delete_node(lst[p].Next[1]);
        }
        else return false;
        for (int i = MAX_LEVEL; i; --i) {
            if (lst[lst[update[i]].Next[i]].Key==num)
                lst[update[i]].Next[i] = lst[lst[update[i]].Next[i]].Next[i];
        }
        return true;
    }
    void new_node(int& p, int key = 0) {
        if (top)
            p = st[top--];
        else
            p = ++node_tot;
        lst[p].Key = key;
        Size++;
    }
    void delete_node(int p) {
        st[++top] = p;
        Size--;
    }

};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */