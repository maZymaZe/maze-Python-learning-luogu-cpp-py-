class Solution {
   public:
    bool isUnique(string astr) {
        int l = astr.size();
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                if (astr[i] == astr[j])
                    return false;
            }
        }
        return true;
    }
};