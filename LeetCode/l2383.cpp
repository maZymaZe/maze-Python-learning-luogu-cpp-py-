class Solution {
   public:
    int minNumberOfHours(int initialEnergy,
                         int initialExperience,
                         vector<int>& energy,
                         vector<int>& experience) {
        int l = energy.size();
        int x = energy[l - 1] + 1, y = experience[l - 1] + 1;
        for (int i = l - 2; i >= 0; i--) {
            x = max({x + energy[i], energy[i] + 1});
            y = max({y - experience[i], experience[i] + 1});
        }
        return max(0, x - initialEnergy) + max(0, y - initialExperience);
    }
};