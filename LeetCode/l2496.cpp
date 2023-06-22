class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int res = 0;
        for (auto& s : strs) {
            bool isDigits = true;
            for (char& c : s) {
                isDigits &= isdigit(c);
            }
            res = max(res, isDigits ? stoi(s) : (int)s.size());
        }
        return res;
    }
};