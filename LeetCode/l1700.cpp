class Solution {
   public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int c[2] = {0};
        for (auto i : students)
            c[i]++;
        int l = students.size();
        for (auto x : sandwiches) {
            if (c[x] == 0) {
                return c[x ^ 1];
            }
            c[x]--;
        }
        return 0;
    }
};