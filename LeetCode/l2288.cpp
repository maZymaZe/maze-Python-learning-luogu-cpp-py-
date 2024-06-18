class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream sin(sentence), sout;
        sout << fixed << setprecision(2);

        vector<string> words;
        string word;
        while (sin >> word) {
            if (word[0] == '$' && word.size() > 1 && all_of(word.begin() + 1, word.end(), ::isdigit)) {
                double price = stoll(word.substr(1, word.size() - 1)) * (1.0 - discount / 100.0);
                sout << '$' << price;
            }
            else {
                sout << word;
            }
            sout << " ";
        }
        string ans = sout.str();
        ans.pop_back();
        return ans;
    }
};
