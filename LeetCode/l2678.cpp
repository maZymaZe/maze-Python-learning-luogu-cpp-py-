class Solution {
   public:
    int countSeniors(vector<string>& details) {
        int r = 0;
        for (const auto& s : details) {
            r += (stoi(s.substr(11, 2)) > 60);
        }
        return r;
    }
};