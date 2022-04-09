class Solution {
   public:
    bool checkIfExist(vector<int>& arr) {
        int mp[3000] = {0};
        for (int i : arr) {
            mp[i + 1200]++;
        }
        for (int i : arr) {
            if (i == 0) {
                if (mp[1200] > 1)
                    return true;
            } else {
                if (2 * i + 1200 < 3000 && 2 * i + 1200 >= 0 &&
                    mp[2 * i + 1200])
                    return true;
            }
        }
        return false;
    }
};