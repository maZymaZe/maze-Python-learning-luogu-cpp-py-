
class Solution {
   public:
    int totalFruit(vector<int>& fruits) {
        int l = fruits.size();
        vector<int> cnt(l);
        int tot = 0, ll = 0, r = 0, ans = 0;
        while (r < l) {
            while (r < l && tot <= 2) {
                if (!cnt[fruits[r]])
                    tot++;
                cnt[fruits[r]]++;
                r++;
                if (tot <= 2)
                    ans = max(r - ll, ans);
            }
            while (r < l && tot > 2) {
                cnt[fruits[ll]]--;
                if (!cnt[fruits[ll]])
                    tot--;
                ll++;
                if (tot <= 2)
                    ans = max(r - ll, ans);
            }
        }
        return ans;
    }
};