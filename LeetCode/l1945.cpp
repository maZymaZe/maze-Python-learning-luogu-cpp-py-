class Solution {
   public:
    int getLucky(string s, int k) {
        string y, x;
        int z;
        for (auto c : s) {
            x += to_string(c - 'a' + 1);
        }
        while (k--) {
            z = 0;
            for (auto c : x) {
                z += (c - '0');
            }
            x = to_string(z);
        }
        return stoi(x);
    }
};