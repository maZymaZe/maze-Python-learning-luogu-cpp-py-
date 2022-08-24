#include <algorithm>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<double> intersection(vector<int>& start1,
                                vector<int>& end1,
                                vector<int>& start2,
                                vector<int>& end2) {
        if (start1[0] > end1[0] ||
            (start1[0] == end1[0] && start1[1] > end1[1]))
            swap(start1, end1);
        if (start2[0] > end2[0] ||
            (start2[0] == end2[0] && start2[1] > end2[1]))
            swap(start2, end2);
        if ((start1[0] == end1[0]) && (start2[0] == end2[0])) {
            if (start1[0] != start2[0])
                return {};
            if (start1[1] >= start2[1] && start1[1] <= end2[1])
                return {(double)start1[0], (double)start1[1]};
            if (start2[1] >= start1[1] && start2[1] <= end1[1])
                return {(double)start1[0], (double)start2[1]};
            return {};
        } else if (start1[0] == end1[0]) {
            double k = 1.0 * (end2[1] - start2[1]) / (end2[0] - start2[0]);
            double b = start2[1] - k * start2[0];
            if (start2[0] <= start1[0] && start1[0] <= end2[0]) {
                double t = k * start1[0] + b;
                if (t >= start1[1] && t <= end1[0])
                    return {(double)start1[0], (double)t};
            }
            return {};
        } else if (start2[0] == end2[0]) {
            double k = 1.0 * (end1[1] - start1[1]) / (end1[0] - start1[0]);
            double b = start1[1] - k * start1[0];
            if (start1[0] <= start2[0] && start2[0] <= end1[0]) {
                double t = k * start2[0] + b;
                if (t >= start2[1] && t <= end2[0])
                    return {(double)start2[0], (double)t};
            }
            return {};
        }
        double k1 = 1.0 * (end1[1] - start1[1]) / (end1[0] - start1[0]);
        double b1 = start1[1] - k1 * start1[0];
        double k2 = 1.0 * (end2[1] - start2[1]) / (end2[0] - start2[0]);
        double b2 = start2[1] - k2 * start2[0];
        if (abs(k1 - k2) < 1e-6) {
            if (abs(b1 - b2) < 1e-6) {
                if (start1[0] >= start2[0] && start1[0] <= end2[0])
                    return {(double)start1[0], (double)start1[1]};
                if (start2[0] >= start1[0] && start2[0] <= end1[0])
                    return {(double)start2[0], (double)start2[1]};
            }
            return {};
        }
        double xx = 1.0 * (b2 - b1) / (k1 - k2);
        if (xx >= start1[0] && xx <= end1[0] && xx >= start2[0] &&
            xx <= end2[0]) {
            return {(double)xx, (double)k1 * xx + b1};
        }
        return {};
    }
};
int main() {
    vector<int> a{0, 0}, b{1, 0}, c{1, 1}, d{0, -1};
    Solution().intersection(a, b, c, d);
}