class Solution {
   public:
    vector<string> rs;
    int uniqueMorseRepresentations(vector<string>& words) {
        int l = words.size();
        rs.resize(l);
        string ss[26] = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                         "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                         "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                         "...-", ".--",  "-..-", "-.--", "--.."};
        for (int i = 0; i < l; i++) {
            for (char x : words[i]) {
                rs[i] += ss[x - 'a'];
            }
        }
        sort(rs.begin(), rs.end());
        return unique(rs.begin(), rs.end()) - rs.begin();
    }
};