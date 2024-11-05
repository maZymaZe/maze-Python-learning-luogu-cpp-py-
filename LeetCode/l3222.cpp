class Solution {
   public:
    string losingPlayer(int x, int y) {
        bool b = true;
        while (x && y > 3) {
            x--;
            y -= 4;
            b = !b;
        }
        return b ? "Bob" : "Alice";
    }
};