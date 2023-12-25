class Solution {
   public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if (tomatoSlices % 2 != 0)
            return {};
        tomatoSlices /= 2;
        if (tomatoSlices >= cheeseSlices && tomatoSlices <= cheeseSlices * 2) {
            return {tomatoSlices - cheeseSlices,
                    2 * cheeseSlices - tomatoSlices};
        }
        return {};
    }
};