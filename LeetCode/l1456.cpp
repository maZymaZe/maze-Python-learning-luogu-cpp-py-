bool ck(char x) {
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        return 1;
    return 0;
}
class Solution {
   public:
    int maxVowels(string s, int k) {
        int cnt = 0, ans = 0, l = s.length();
        for (int i = 0; i < k; i++) {
            cnt += ck(s[i]);
        }
        ans = max(ans, cnt);
        for (int i = k; i < l; i++) {
            cnt -= ck(s[i - k]);
            cnt += ck(s[i]);
            ans = max(ans, cnt);
        }
        return ans;
    }
};