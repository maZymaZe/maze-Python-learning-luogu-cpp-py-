class Solution {
   public:
    string rankTeams(vector<string>& votes) {
        int vo[27][27] = {0};
        int l = votes[0].size();
        for (const string& v : votes) {
            for (int i = 0; i < l; i++) {
                vo[v[i] - 'A'][i]++;
            }
        }
        sort(votes[0].begin(), votes[0].end(),
             [&](const char& a, const char& b) {
                 for (int i = 0; i < l; i++) {
                     if (vo[a - 'A'][i] < vo[b - 'A'][i])
                         return false;
                     if (vo[a - 'A'][i] > vo[b - 'A'][i])
                         return true;
                 }
                 return a < b;
             });
        return votes[0];
    }
};