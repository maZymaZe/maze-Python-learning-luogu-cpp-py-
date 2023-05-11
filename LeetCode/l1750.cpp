class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right && s[left] == s[right]) {
            char c = s[left];
            while (left <= right && s[left] == c) {
                left++;
            }
            while (left <= right && s[right] == c) {
                right--;
            }
        }
        return right - left + 1;
    }
};