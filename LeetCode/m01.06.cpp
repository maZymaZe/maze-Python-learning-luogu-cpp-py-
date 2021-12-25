class Solution {
   public:
    string compressString(string S) {
        int l = S.size();
        int pre = 0, cnt = 0;
        string ans;
        for (int i = 0; i < l; i++) {
            if (pre == S[i])
                cnt++;
            else {
                if (pre != 0) {
                    ans += (char)pre + to_string(cnt);
                }
                pre = S[i];
                cnt = 1;
            }
        }
        if (pre != 0) {
            ans += (char)pre + to_string(cnt);
        }
        if (ans.size() < l)
            return ans;
        return S;
    }
};