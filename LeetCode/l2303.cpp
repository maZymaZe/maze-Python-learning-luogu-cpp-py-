class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double totalTax = 0;
        int lower = 0;
        for (auto &bracket: brackets) {
            int upper = bracket[0], percent = bracket[1];
            int tax = (min(income, upper) - lower) * percent;
            totalTax += tax;
            if (income <= upper) {
                break;
            }
            lower = upper;
        }
        return (double)totalTax / 100.0;
    }
};
