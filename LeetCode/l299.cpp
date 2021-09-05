class Solution {
   public:
    string getHint(string secret, string guess) {
        int c[10] = {0}, a = 0, b = 0;
        for (auto d : secret)
            c[d - '0']++;
        int l = secret.size();
        for (int i = 0; i < l; i++) {
            if (secret[i] == guess[i])
                a++, c[secret[i] - '0']--;
        }
        for (int i = 0; i < l; i++) {
            if (secret[i] != guess[i] && c[guess[i] - '0'])
                b++, c[guess[i] - '0']--;
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};