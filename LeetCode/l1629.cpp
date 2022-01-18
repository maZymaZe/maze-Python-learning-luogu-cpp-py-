class Solution {
   public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans = keysPressed[0];
        int mt = releaseTimes[0], l = keysPressed.size();
        for (int i = 1; i < l; i++) {
            if (releaseTimes[i] - releaseTimes[i - 1] >= mt) {
                if (releaseTimes[i] - releaseTimes[i - 1] > mt) {
                    ans = keysPressed[i];
                } else if (keysPressed[i] > ans)
                    ans = keysPressed[i];
                mt = releaseTimes[i] - releaseTimes[i - 1];
            }
        }
        return ans;
    }
};