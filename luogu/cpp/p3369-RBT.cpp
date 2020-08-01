#include <cstdio>
struct RBTnode {
    int Val, Size, Cnt;
    bool Color;            // 0----B,1----R
    int Father, Child[2];  // 0----L,1----R
};
const int MAXN = 100100;
const int INF = 0x7FFFFFFF;
class RBT {
   protected:
    RBTnode tree[MAXN];
    int stk[MAXN] = {0}, stp = 0, tot = 0, rt = 0;
    void pushup(int Root) {
        tree[Root].Size = tree[tree[Root].Child[0]].Size +
                          tree[tree[Root].Child[1]].Size + tree[Root].Cnt;
    }
    bool get(int Root) { return Root == tree[tree[Root].Father].Child[1]; }
    int newnode(int val) {
        int Root = stp ? stk[stp--] : ++tot;
        tree[Root] = (RBTnode){val, 1, 1, 1, 0, 0, 0};
        return Root;
    }
    void rotate(int Root, bool c) {  // 0----L,1----R
        int newRoot = tree[Root].Child[!c];

        if (tree[Root].Father)
            tree[tree[Root].Father].Child[get(Root)] = newRoot;
        else
            rt = newRoot;
        tree[newRoot].Father = tree[Root].Father;

        tree[Root].Child[!c] = tree[newRoot].Child[c];
        if (tree[newRoot].Child[c]) {
            tree[tree[newRoot].Child[c]].Father = Root;
        }

        tree[newRoot].Child[c] = Root;
        tree[Root].Father = newRoot;
        pushup(Root);
        pushup(newRoot);
    }
    void insert_fix(int Root) {
        while (tree[tree[Root].Father].Color) {
            int father = tree[Root].Father, grandfather = tree[father].Father;
            bool wh = !(get(father));
            int uncle = tree[grandfather].Child[wh];
            if (tree[uncle].Color) {
                tree[uncle].Color = 0;
                tree[father].Color = 0;
                tree[grandfather].Color = 1;
                Root = grandfather;
            } else {
                if (Root == tree[father].Child[wh])
                    rotate(Root=father, !wh);
                else {
                    tree[grandfather].Color = 1;
                    tree[father].Color = 0;
                    rotate(grandfather, wh);
                }
            }
        }
        tree[rt].Color = 0;
    }
    void delete_update(int Root) {
        for (int i = Root; i; i = tree[i].Father) {
            tree[i].Size--;
        }
    }
    void delete_fix(int Root) {
        while (Root != rt && !tree[Root].Color) {
            bool wh = !get(Root);
            int father = tree[Root].Father, uncle = tree[father].Child[wh];
            if (tree[uncle].Color) {
                tree[uncle].Color = 0;
                tree[father].Color = 1;
                rotate(father, !wh);
                uncle = tree[father].Child[wh];  //保持对应的uncle位置
            } else {
                if (!tree[tree[uncle].Child[0]].Color &&
                    !tree[tree[uncle].Child[1]].Color) {
                    tree[uncle].Color = 1;
                    Root = father;
                } else {
                    if (!tree[tree[uncle].Child[wh]].Color) {
                        tree[tree[uncle].Child[!wh]].Color = 0;
                        tree[uncle].Color = 1;
                        rotate(uncle, wh);
                        uncle=tree[father].Child[wh];//保持对应的uncle位置
                    }
                    tree[uncle].Color = tree[father].Color;
                    tree[tree[uncle].Child[wh]].Color = tree[father].Color = 0;
                    rotate(father, !wh);
                    break;
                }
            }
        }
        tree[Root].Color = 0;
    }

   public:
    void Insert(int val) {
        int Root = rt, f = 0;
        while (Root) {
            tree[Root].Size++, f = Root;
            if (tree[Root].Val == val) {
                tree[Root].Cnt++;
                return;
            } else
                Root = tree[Root].Child[tree[Root].Val < val];
        }
        Root = newnode(val);
        if (f) {
            tree[f].Child[tree[f].Val < val] = Root;
        } else
            rt = Root;
        tree[Root].Father = f;
        insert_fix(Root);
    }
    int Kth(int k) {
        int Root = rt;
        while (Root) {
            if (tree[tree[Root].Child[0]].Size >= k)
                Root = tree[Root].Child[0];
            else if (k > tree[Root].Cnt + tree[tree[Root].Child[0]].Size) {
                k -= tree[Root].Cnt + tree[tree[Root].Child[0]].Size;
                Root = tree[Root].Child[1];
            } else
                break;
        }
        return tree[Root].Val;
    }
    void Delete(int val) {
        int Root = rt;
        while (Root && tree[Root].Val != val) {
            Root = tree[Root].Child[tree[Root].Val < val];
        }
        if (!Root)
            return;
        if (tree[Root].Cnt > 1) {
            tree[Root].Cnt--;
            delete_update(Root);
            return;
        }
        int sufR = Root, g = 0;
        if (tree[Root].Child[0] && tree[Root].Child[1]) {
            sufR = tree[Root].Child[1];
            while (tree[sufR].Child[0])
                sufR = tree[sufR].Child[0];
        }  //都有的话就是最小那个
        g = tree[sufR].Child[!tree[sufR].Child[0]];  //只有1个儿子---剩下那个
        if (g)
            tree[g].Father = tree[sufR].Father;  //保持tree[0]空白
        if (!tree[sufR].Father)
            rt = g;
        else
            tree[tree[sufR].Father].Child[get(sufR)] = g;
        if (Root != sufR) {
            tree[Root].Val = tree[sufR].Val;
            tree[Root].Cnt = tree[sufR].Cnt;
        }
        delete_update(tree[sufR].Father);
        for (int i = tree[sufR].Father; i && tree[sufR].Cnt > 1 && i != Root;
             i = tree[i].Father) {
            tree[i].Size -= tree[sufR].Cnt;
            tree[i].Size++;
        }
        if (!tree[sufR].Color)
            delete_fix(g);
        stk[++stp] = sufR;
    }
    int Get_rank(int val) {
        if (!rt)
            return -1;
        int Root = rt, sum = 0;
        while (Root) {
            if (val == tree[Root].Val)
                return tree[tree[Root].Child[0]].Size + sum + 1;
            else if (val < tree[Root].Val)
                Root = tree[Root].Child[0];
            else
                sum += tree[Root].Cnt + tree[tree[Root].Child[0]].Size,
                    Root = tree[Root].Child[1];
        }
        return sum + 1;
    }
    int Suf(int val) {
        int Root = rt, ans = INF;
        while (Root) {
            if (tree[Root].Val > val) {
                ans = tree[Root].Val;
                Root = tree[Root].Child[0];
            } else {
                Root = tree[Root].Child[1];
            }
        }
        return ans;
    }
    int Pre(int val) {
        int Root = rt, ans = -INF;
        while (Root) {
            if (tree[Root].Val < val) {
                ans = tree[Root].Val;
                Root = tree[Root].Child[1];
            } else {
                Root = tree[Root].Child[0];
            }
        }
        return ans;
    }
};
RBT rbt1;
int main() {
    int n, t, x;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &t, &x);
        if (t == 1) {
            rbt1.Insert(x);
        } else if (t == 2) {
            rbt1.Delete(x);
        } else if (t == 3) {
            printf("%d\n", rbt1.Get_rank(x));
        } else if (t == 4) {
            printf("%d\n", rbt1.Kth(x));
        } else if (t == 5) {
            printf("%d\n", rbt1.Pre(x));
        } else if (t == 6) {
            printf("%d\n", rbt1.Suf(x));
        }
    }
    return 0;
}