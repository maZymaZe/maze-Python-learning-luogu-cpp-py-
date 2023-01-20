class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> activeMinutes;
        for (auto &&log : logs) {
            int id = log[0], time = log[1];
            activeMinutes[id].emplace(time);
        }
        vector<int> answer(k);
        for (auto &&[_, minutes] : activeMinutes) {
            int activeCount = minutes.size();
            answer[activeCount - 1]++;
        }
        return answer;
    }
};
