struct PR {
    int v, p;
    bool operator<(const PR& x) const { return v == x.v ? p < x.p : v < x.v; }
};
class MKAverage {
   public:
    int M, K, L;
    vector<int> log;
    vector<int> st;
    long long tot;
    set<PR> s[3];
    int sz;
    MKAverage(int m, int k) {
        M = m, K = k, L = m - 2 * k;
        sz = 0;
        tot = 0;
        st.clear(), log.clear();
    }

    void addElement(int num) {
        if (sz < M) {
            PR nx = {num, sz};
            s[2].insert(nx);
            log.push_back(num);
            st.push_back(2);
            sz++;
            if (sz == M) {
                for (int i = 0; i < K; i++) {
                    auto it = s[2].begin();
                    s[0].insert(*it);
                    st[it->p] = 0;
                    s[2].erase(it);
                }
                for (int i = 0; i < L; i++) {
                    auto it = s[2].begin();
                    s[1].insert(*it);
                    st[it->p] = 1;
                    tot += it->v;
                    s[2].erase(it);
                }
            }
        } else {
            PR nx = {num, sz};
            log.push_back(num);

            auto max0 = s[0].end();
            --max0;
            if (nx < *max0) {
                s[0].insert(nx);
                st.push_back(0);
            } else {
                auto min2 = s[2].begin();
                if (*min2 < nx) {
                    s[2].insert(nx);
                    st.push_back(2);
                } else {
                    s[1].insert(nx);
                    tot += num;
                    st.push_back(1);
                }
            }
            if (st[sz - M] == 1)
                tot -= log[sz - M];
            s[st[sz - M]].erase({log[sz - M], sz - M});
            sz++;
            while (s[0].size() != K) {
                if (s[0].size() < K) {
                    auto min1 = s[1].begin();
                    st[min1->p] = 0;
                    s[0].insert(*min1);
                    tot -= min1->v;
                    s[1].erase(min1);
                } else if (s[0].size() > K) {
                    auto max0 = s[0].end();
                    --max0;
                    st[max0->p] = 1;
                    s[1].insert(*max0);
                    tot += max0->v;
                    s[0].erase(max0);
                }
            }
            while (s[2].size() != K) {
                if (s[2].size() > K) {
                    auto min2 = s[2].begin();
                    st[min2->p] = 1;
                    s[1].insert(*min2);
                    tot += min2->v;
                    s[2].erase(min2);
                } else if (s[2].size() < K) {
                    auto max1 = s[1].end();
                    --max1;
                    st[max1->p] = 2;
                    s[2].insert(*max1);
                    tot -= max1->v;
                    s[1].erase(max1);
                }
            }
        }
    }

    int calculateMKAverage() {
        if (sz < M)
            return -1;
        return tot / L;
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */