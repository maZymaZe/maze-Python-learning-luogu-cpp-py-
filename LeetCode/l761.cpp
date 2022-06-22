class Solution {
   public:
    string makeLargestSpecial(string s) {
        vector<string> v;
        for (int i = 0, cur = 0, last = 0; i < s.size(); ++i) {
            (s[i] == '1') ? cur++ : cur--;
            if (cur == 0) {
                v.push_back("1");
                v.back() +=
                    makeLargestSpecial(s.substr(last + 1, i - last - 1)) + '0';
                last = i + 1;
            }
        }
        sort(v.begin(), v.end(), greater<string>());

        string res;
        for (auto& r : v) {
            res += r;
        }
        return res;
    }
};