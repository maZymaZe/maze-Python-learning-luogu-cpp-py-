#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 20;
struct xxx {
    int len, link;
    ll dx, sum = 0;
    map<char, int> next;
} st[maxn];
int sz, last, n;
void sam_build() {
    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
    last = 0;
}
void sam_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].dx = 1;
    // st[cur].sum=1;
    int p = last;

    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }

    if (p == -1)
        st[cur].link = 0;
    else {
        int q = st[p].next[c];

        if (st[p].len + 1 == st[q].len)
            st[cur].link = q;
        else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].link = st[q].link;
            st[clone].next = st[q].next;

            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }

            st[cur].link = st[q].link = clone;
        }
    }

    last = cur;
}
int A[maxn], t[maxn];
bool ggds[maxn] = {false};
void ddfs(int g) {
    if (st[g].len == n) {
        st[g].sum = max(1ll, st[g].dx);
        return;
    }

    for (auto ddg : st[g].next) {
        if (!ggds[ddg.second])
            ddfs(ddg.second);

        st[g].sum += st[ddg.second].sum;
    }

    st[g].sum += max(1ll, st[g].dx);
    ggds[g] = true;
}
/*
string dfs(int g,int k,string s)//改成dfs大小
{
    //cout<<s<<endl;
    if(g&&k<=max(1ll,st[g].dx))return s;
    //cout<<g<<' '<<st[g].sum<<endl;
    if(g)k-=max(1ll,st[g].dx);
    //cout<<k<<' '<<"1111111111"<<endl;
    for(auto ddg:st[g].next)
    {
        //cout<<' '<<g<<' '<<ddg.first<<' '<<k<<endl;
        if(st[ddg.second].sum>=k)return dfs(ddg.second,k,s+=(char)ddg.first);
        else k-=st[ddg.second].sum;
    }
    return s;
}*/

string dfs(int g, int k, string s) {  //改成dfs大小
    while (k) {
        if (g && k <= max(1ll, st[g].dx))
            return s;

        // cout<<g<<' '<<st[g].sum<<endl;
        if (g)
            k -= max(1ll, st[g].dx);

        // cout<<k<<endl;
        for (auto ddg : st[g].next) {
            // cout<<' '<<g<<' '<<ddg.first<<' '<<st[ddg.second].sum<<'
            // '<<k<<endl;
            if (st[ddg.second].sum >= k) {
                g = ddg.second;
                s += (char)ddg.first;
                break;
            } else
                k -= st[ddg.second].sum;
        }
    }

    return s;
}

int main() {
    string s;
    cin >> s;
    sam_build();
    n = s.length();

    for (int i = 0; i < n; ++i)
        sam_extend(s[i]);

    int op, k;
    cin >> op >> k;

    for (int i = 1; i < sz; ++i)
        t[st[i].len]++;

    for (int i = 1; i < sz; ++i)
        t[i] += t[i - 1];

    for (int i = 1; i < sz; ++i)
        A[t[st[i].len]--] = i;

    if (op) {
        for (int i = sz - 1; i > 0; --i) {
            int dq = A[i];
            st[st[dq].link].dx += st[dq].dx;
            // cout<<dq<<endl;
            // cout<<dq<<' '<<st[dq].dx<<' '<<st[dq].link<<endl;
        }
    }

    ddfs(0);
    string gss = dfs(0, k, "");

    // cout<<st[0].sum<<endl;
    // cout<<1<<endl;
    if (st[0].sum < k)
        cout << -1 << endl;
    else
        cout << gss << endl;

    // cout<<1<<endl;
    return 0;
}