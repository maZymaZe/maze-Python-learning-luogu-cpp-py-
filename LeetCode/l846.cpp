class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int l = hand.size();
        if (l % groupSize)
            return false;
        map<int, int> s;
        for (int i = 0; i < l; i++)
            ++s[hand[i]];
        for (auto iter = s.begin(); iter != s.end(); ++iter) {
            int num = iter->first;
            int occ = iter->second;
            if (occ > 0) {
                auto it = next(iter);
                for (auto i = 1; i < groupSize; ++i, ++it) {
                    if (it != s.end() && it->first == num + i &&
                        it->second >= occ) {
                        it->second -= occ;
                    } else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};