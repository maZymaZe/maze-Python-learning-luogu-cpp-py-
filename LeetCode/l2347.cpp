class Solution {
   public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_set<char> suitsSet;
        for (char suit : suits) {
            suitsSet.emplace(suit);
        }
        if (suitsSet.size() == 1) {
            return "Flush";
        }
        unordered_map<int, int> h;
        for (int rank : ranks) {
            h[rank]++;
        }
        if (h.size() == 5) {
            return "High Card";
        }
        for (auto [_, val] : h) {
            if (val > 2) {
                return "Three of a Kind";
            }
        }
        return "Pair";
    }
};
