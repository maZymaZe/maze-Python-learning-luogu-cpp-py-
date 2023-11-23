class Solution {
   public:
    string entityParser(string text) {
        string ret;
        int l = text.size();
        for (int i = 0; i < l; i++) {
            if (text[i] == '&') {
                if (text.substr(i + 1, 3) == "lt;") {
                    ret += '<', i += 3;
                } else if (text.substr(i + 1, 3) == "gt;") {
                    ret += '>', i += 3;
                } else if (text.substr(i + 1, 4) == "amp;") {
                    ret += '&', i += 4;
                } else if (text.substr(i + 1, 5) == "quot;") {
                    ret += '"', i += 5;
                } else if (text.substr(i + 1, 5) == "apos;") {
                    ret += '\'', i += 5;
                } else if (text.substr(i + 1, 6) == "frasl;") {
                    ret += '\/', i += 6;
                } else
                    ret += text[i];
            } else {
                ret += text[i];
            }
        }
        return ret;
    }
};