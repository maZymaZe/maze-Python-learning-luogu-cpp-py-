class Solution {
   public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(students.begin(), students.end());
        sort(seats.begin(), seats.end());
        int answer = 0, l = seats.size();
        for (int i = 0; i < l; i++) {
            answer += abs(students[i] - seats[i]);
        }
        return answer;
    }
};