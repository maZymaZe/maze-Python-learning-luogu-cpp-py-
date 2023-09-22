class Solution {
   public:
    int distMoney(int money, int children) {
        if (money < children)
            return -1;
        money -= children;
        if (money == children * 7)
            return children;
        if (money > children * 7)
            return children - 1;
        return max(0, (money / 7) - (money == children * 7 - 4));
    }
};