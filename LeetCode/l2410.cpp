class Solution {
   public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int lp = players.size(), lt = trainers.size();
        int p = 0, t = 0;
        while (p < lp && t < lt) {
            if (players[p] <= trainers[t]) {
                ++p;
            }
            ++t;
        }
        return p;
    }
};