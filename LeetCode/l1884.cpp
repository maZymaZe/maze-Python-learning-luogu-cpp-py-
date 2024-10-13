class Solution {
   public:
    int twoEggDrop(int n) {
        for (int i = 1; i < 1000; i++) {
            if ((i + 1) * i / 2 >= n)
                return i;
        }
        return 0;
    }
};