class WordsFrequency {
   public:
    unordered_map<string, int> mp;
    WordsFrequency(vector<string>& book) {
        for (const string& word : book)
            mp[word]++;
    }

    int get(string word) { return mp[word]; }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */