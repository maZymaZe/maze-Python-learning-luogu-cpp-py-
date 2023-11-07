class Solution {
   public:
    int vowelStrings(vector<string>& words, int left, int right) {
        // 返回字符是否是元音字符
        auto f = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                   ch == 'u';
        };
        int cnt = 0;
        // 枚举区间[left,
        // right]的所有字符串，校验每个字符串首字母和尾字母是否为元音字母
        for (int i = left; i <= right; i++) {
            cnt += f(words[i][0]) && f(words[i][words[i].size() - 1]) ? 1 : 0;
        }
        return cnt;
    }
};
