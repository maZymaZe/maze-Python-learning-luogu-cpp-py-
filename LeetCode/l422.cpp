class Solution {
   public:
    bool validWordSquare(vector<string>& words) {
        int n = words.size(), m = words[0].size();
        if (n != m)
            return false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                if (words[j].size() - 1 < i)
                    return false;
                if (j >= n)
                    return false;
                if (words[i][j] != words[j][i])
                    return false;
            }
        }
        return true;
    }
};