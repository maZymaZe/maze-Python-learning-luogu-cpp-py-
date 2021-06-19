class Solution {
   public:
    int maxLength(vector<string>& arr) {
        int l = arr.size();
        int lim = 1 << l;
        int c[26], ans = 0;
        for (int i = 0; i < lim; i++) {
            memset(c, 0, sizeof(c));
            int cnt = 0, f = 1;
            for (int j = 0; j < l; j++) {
                if (i & (1 << j)) {
                    for (int k = 0; k < arr[j].length(); k++) {
                        if (c[arr[j][k] - 'a']) {
                            f = 0;
                            break;
                        } else
                            cnt++, c[arr[j][k] - 'a']++;
                    }
                }
                if (f == 0)
                    break;
            }
            if(f==0)continue;
            ans = max(ans, cnt);
        }
        return ans;
    }
};