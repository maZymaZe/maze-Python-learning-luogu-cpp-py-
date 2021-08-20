#include <vector>
using namespace std;
class Solution {
   public:
    int compress(vector<char>& chars) {
        int c = 1, l = chars.size(), ans = chars.size(), ll = 0, p = 0;
        for (int i = 1; i < l; i++) {
            if (chars[i] == chars[i - 1]) {
                c++;
            } else {
                if (c > 1) {
                    chars[p++] = chars[ll];

                    int tt = 0, cc = c;
                    while (c)
                        c /= 10, tt++;
                    ans -= (cc - tt - 1);

                    for (int j = p + tt - 1; j >= p; j--) {
                        chars[j] = (cc % 10) + '0';
                        cc /= 10;
                    }
                    ll = i;
                    p = p + tt;
                } else {
                    chars[p++] = chars[ll];
                    ll = i;
                }
                c = 1;
            }
        }
        if (c > 1) {
            chars[p++] = chars[ll];

            int tt = 0, cc = c;
            while (c)
                c /= 10, tt++;
            ans -= (cc - tt - 1);

            for (int j = p + tt - 1; j >= p; j--) {
                chars[j] = (cc % 10) + '0';
                cc /= 10;
            }
            p = p + tt - 1;
        } else {
            chars[p++] = chars[ll];
        }
        return ans;
    }
};
int main() {
    vector<char> x = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    Solution().compress(x);
}