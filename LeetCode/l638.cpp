class Solution {
   public:
    int shoppingOffers(vector<int>& price,
                       vector<vector<int>>& special,
                       vector<int>& needs) {
        int res = 0;
        for (int i = 0; i < needs.size(); i++)
            res += needs[i] * price[i];
        for (int i = 0; i < special.size(); i++) {
            vector<int> clone = needs;
            int j = 0;
            for (; j < clone.size(); j++) {
                clone[j] = clone[j] - special[i][j];
                if (clone[j] < 0)
                    break;
            }
            if (j == clone.size())
                res = min(
                    res, special[i][j] + shoppingOffers(price, special, clone));
        }
        return res;
    }
};