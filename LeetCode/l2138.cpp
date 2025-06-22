class Solution {
   public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int n = s.size();
        for (int i = 0; i < n; i += k) {
            string part = s.substr(i, k);
            if (part.size() < k) {
                part.append(k - part.size(), fill);
            }
            result.push_back(part);
        }
        return result;
    }
};