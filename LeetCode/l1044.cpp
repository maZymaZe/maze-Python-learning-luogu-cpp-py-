class Solution {
   public:
    unordered_set<long long> st;
    unordered_set<long long> st2;
    unordered_set<long long> st3;
    int ansl, sz;
    const int MOD = 10000007;
    const int MOD2 = 19260817;
    const int MOD3 = 1e9 +7;
    bool check(string& S, int len) {
       // st.clear();
        st2.clear();
        st3.clear();

        long long hs = 0, t = 1,hs2=0,t2=1,hs3=0,t3=1;
      /*  for (int i = 1; i < len; i++)
            t *= 317, t %= MOD;
        for (int i = 0; i < len; i++) {
            hs = (hs * 317 + S[i]) % MOD;
        }
        st.insert(hs);*/
        for (int i = 1; i < len; i++)
            t2 *= 2927, t2 %= MOD2;
        for (int i = 0; i < len; i++) {
            hs2 = (hs2 * 2927 + S[i]) % MOD2;
        }
        st2.insert(hs2);
        for (int i = 1; i < len; i++)
            t3 *= 4001, t3 %= MOD3;
        for (int i = 0; i < len; i++) {
            hs3 = (hs3 * 4001 + S[i]) % MOD3;
        }
        st3.insert(hs3);
        for (int i = 1; i <= sz - len; i++) {
            hs2 -= S[i - 1] * t2;
            hs2 = (hs2 % MOD2 + MOD2) % MOD2;
            hs2 = (hs2 * 2927 + S[i + len - 1]) % MOD2;
       /*     hs -= S[i - 1] * t;
            hs = (hs % MOD + MOD) % MOD;
            hs = (hs * 317 + S[i + len - 1]) % MOD;*/
            hs3 -= S[i - 1] * t3;
            hs3 = (hs3 % MOD3 + MOD3) % MOD3;
            hs3 = (hs3 * 4001 + S[i + len - 1]) % MOD3;
            if (st2.count(hs2)&&st3.count(hs3)) {
                ansl = i;
                return true;
            }
        //    st.insert(hs);
            st2.insert(hs2);
            st3.insert(hs3);
        }
        return false;
    }
    string longestDupSubstring(string S) {
        sz = S.size();
        int l = 0, r = S.size();
        while (l < r) {
            int mid = l+(r-l+5)/6;
            if (check(S, mid))
                l = mid;
            else
                r = mid - 1;
        }
        return S.substr(ansl, l);
    }
};