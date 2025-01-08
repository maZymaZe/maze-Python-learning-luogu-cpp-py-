class Solution {
   public:
    string largestGoodInteger(string num) {
        int ans = -1;
        int l = num.size();
        for (int i = 2; i < l; i++) {
            if (num[i] == num[i - 1] && num[i] == num[i - 2])
                ans = max(ans, (int)num[i]);
        }
        if (ans == -1)
            return "";
        return string(3, ans);
    }
};