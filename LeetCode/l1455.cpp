class Solution {
public:
    bool isPrefix(const string &sentence, int start, int end, const string &searchWord) {
        for (int i = 0; i < searchWord.size(); i++) {
            if (start + i >= end || sentence[start + i] != searchWord[i]) {
                return false;
            }
        }
        return true;
    }

    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size(), index = 1, start = 0, end = 0;
        while (start < n) {
            while (end < n && sentence[end] != ' ') {
                end++;
            }
            if (isPrefix(sentence, start, end, searchWord)) {
                return index;
            }

            index++;
            end++;
            start = end;
        }
        return -1;
    }
};
