class Solution {
   public:
    bool isp(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int countOfSubstrings(string word, int k) {
        int cnt[266] = {0}, tot = 0, l = word.size();
        int p = 0, q = 0, INF = 0x3f3f3f3f;
        vector<int> v1(l), ps(l + 1);
        while (p < l) {
            while (q < l && tot < 5) {
                if (isp(word[q])) {
                    cnt[word[q]]++;
                    if (cnt[word[q]] == 1)
                        tot++;
                }
                q++;
            }
            if (q == l && tot < 5)
                v1[p] = INF;
            else
                v1[p] = q - 1;
            if (isp(word[p])) {
                cnt[word[p]]--;
                if (cnt[word[p]] == 0)
                    tot--;
            }
            p++;
        }
        for (int i = 1; i <= l; i++) {
            ps[i] = ps[i - 1] + (!isp(word[i - 1]));
        }
        long long ans = 0;
        for (int i = 0; i < l; i++) {
            if (v1[i] == INF)
                break;
            int s = i, t = l, mid;
            int lim1, lim2;
            while (s + 1 < t) {
                mid = (s + t) / 2;
                if (ps[mid + 1] - ps[i] < k)
                    s = mid;
                else
                    t = mid;
            }
            if (t == l)
                continue;
            lim1 = t;
            s = i, t = l;
            while (s + 1 < t) {
                mid = (s + t) / 2;
                if (ps[mid + 1] - ps[i] < k + 1)
                    s = mid;
                else
                    t = mid;
            }
            if (ps[s + 1] - ps[i] == k + 1)
                lim2 = s - 1;
            else
                lim2 = s;
            ans += max(0, lim2 - max(v1[i], lim1) + 1);
        }
        return ans;
    }
};