class Solution {
   public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() > str2.size())
            swap(str1, str2);
        while (str1.size()) {
            if (str2.substr(0, str1.size()) == str1) {
                str2 = str2.substr(str1.size(), str2.size());
            } else
                return "";
            if (str1.size() > str2.size())
                swap(str1, str2);
        }
        return str2;
    }
};