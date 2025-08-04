class Solution {
   public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        vector<int> v1, v2;
        sort(basket1.begin(), basket1.end());
        sort(basket2.begin(), basket2.end());
        int l = basket1.size(), p1 = 0, p2 = 0;
        long long ans = 0, mmi = min(basket1[0], basket2[0]);
        while (p1 < l && p2 < l) {
            if (basket1[p1] < basket2[p2]) {
                if (p1 + 1 < l && basket1[p1] == basket1[p1 + 1]) {
                    v1.push_back(basket1[p1]);
                    p1 += 2;
                } else {
                    return -1;
                }
            } else if (basket1[p1] > basket2[p2]) {
                if (p2 + 1 < l && basket2[p2] == basket2[p2 + 1]) {
                    v2.push_back(basket2[p2]);
                    p2 += 2;
                } else {
                    return -1;
                }
            } else {
                p1++;
                p2++;
            }
        }
        while (p1 < l) {
            if (p1 + 1 < l && basket1[p1] == basket1[p1 + 1]) {
                v1.push_back(basket1[p1]);
                p1 += 2;
            } else {
                return -1;
            }
        }
        while (p2 < l) {
            if (p2 + 1 < l && basket2[p2] == basket2[p2 + 1]) {
                v2.push_back(basket2[p2]);
                p2 += 2;
            } else {
                return -1;
            }
        }
        int l1 = v1.size();
        for (int i = 0; i < l1; i++) {
            ans += min({(long long)v1[i], (long long)v2[l1 - 1 - i], mmi * 2});
        }
        return ans;
    }
};