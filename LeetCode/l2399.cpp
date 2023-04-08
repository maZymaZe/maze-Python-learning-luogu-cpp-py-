class Solution {
   public:
    bool checkDistances(string s, vector<int>& distance) {
        int c[26][2] = {0};
        int l = s.size();
        for (int i = 0; i < l; i++) {
            if (c[s[i] - 'a'][0])
                c[s[i] - 'a'][1] = i + 1;
            else
                c[s[i] - 'a'][0] = i + 1;
        }
        for (int i = 0; i < 26; i++) {
            if (c[i][0]) {
                if (c[i][1] - c[i][0] != distance[i] + 1)
                    return false;
            }
        }
        return true;
    }
};