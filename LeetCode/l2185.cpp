class Solution {
   public:
    int prefixCount(vector<string>& words, string pref) {
        int tot = 0, l = pref.size();
        for (auto& i : words) {
            tot += (i.size() >= l && i.substr(0, l) == pref);
        }
        return tot;
    }
};