class Solution {
   public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int l = shifts.size();
        for (int i = l - 2; i >= 0; i--)
            (shifts[i] += shifts[i + 1]) %= 26;
        for (int i = 0; i < l; i++)
            S[i] = ((S[i] - 'a') + shifts[i]) % 26 + 'a';
        return S;
    }
};