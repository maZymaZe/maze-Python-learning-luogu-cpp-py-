class Solution {
   public:
    vector<int> masterMind(string solution, string guess) {
        int a1 = 0, a2 = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < 4; i++)
            mp[solution[i]]++;
        for (int i = 0; i < 4; i++) {
            if (solution[i] == guess[i])
                a1++;
            if (mp[guess[i]])
                mp[guess[i]]--, a2++;
        }
        return {a1, a2 - a1};
    }
};