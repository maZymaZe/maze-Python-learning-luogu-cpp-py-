class Solution {
   public:
    vector<bool> visited;

    bool check_translate(const string& a,
                         const string& b)  // a和b只有一个字符不相同
    {
        if (a.size() != b.size())
            return false;
        int n = a.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (a[i] != b[i])
                cnt += 1;
        return cnt == 1;
    }

    bool dfs(const string& curWord,
             const string& endWord,
             const vector<string>& wordList,
             vector<string>& path) {  //回溯 记忆化  dfs
        if (curWord == endWord)
            return true;
        int n = wordList.size();
        for (int i = 0; i < n; i++) {
            if (visited[i] == true ||
                check_translate(curWord, wordList[i]) == false)
                continue;
            visited[i] = true;
            path.push_back(wordList[i]);
            if (dfs(wordList[i], endWord, wordList, path) == true)
                return true;
            path.pop_back();  //回溯
            // visited[i] = false;
            // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        }
        return false;
    }

    vector<string> findLadders(string beginWord,
                               string endWord,
                               vector<string>& wordList) {
        int n = wordList.size();
        visited = vector<bool>(n, false);
        vector<string> path = {beginWord};

        if (dfs(beginWord, endWord, wordList, path) == true)
            return path;
        return vector<string>{};
    }
};