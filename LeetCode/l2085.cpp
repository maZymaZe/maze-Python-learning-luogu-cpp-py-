class Solution {
   public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        // 统计字符串出现频率
        unordered_map<string, int> freq1, freq2;
        for (const string& w : words1) {
            ++freq1[w];
        }
        for (const string& w : words2) {
            ++freq2[w];
        }

        // 遍历 words1 出现的字符并判断是否满足要求
        int res = 0;
        for (const auto& [w, cnt1] : freq1) {
            if (cnt1 == 1 && freq2[w] == 1) {
                ++res;
            }
        }
        return res;
    }
};
