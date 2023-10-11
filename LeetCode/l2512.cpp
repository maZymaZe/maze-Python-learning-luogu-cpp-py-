class Solution {
   public:
    vector<int> topStudents(vector<string>& positive_feedback,
                            vector<string>& negative_feedback,
                            vector<string>& report,
                            vector<int>& student_id,
                            int k) {
        unordered_map<std::string, int> words;
        for (const auto& word : positive_feedback) {
            words[word] = 3;
        }
        for (const auto& word : negative_feedback) {
            words[word] = -1;
        }
        vector<vector<int>> A;
        for (int i = 0; i < report.size(); i++) {
            stringstream ss;  // stream根据空格分词
            string w;
            int score = 0;
            ss << report[i];
            while (ss >> w) {
                if (words.count(w)) {
                    score += words[w];
                }
            }
            A.push_back({-score, student_id[i]});
        }
        sort(A.begin(), A.end());
        vector<int> top_k;
        for (int i = 0; i < k; i++) {
            top_k.push_back(A[i][1]);
        }
        return top_k;
    }
};
