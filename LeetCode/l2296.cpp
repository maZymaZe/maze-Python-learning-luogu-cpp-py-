class TextEditor {
   public:
    list<char> ls;
    list<char>::iterator it;
    TextEditor() { it = ls.begin(); }

    void addText(string text) {
        for (char c : text) {
            it = ls.insert(it, c);
            ++it;
        }
    }

    int deleteText(int k) {
        int ret = 0;

        for (int i = 0; i < k; i++) {
            if (it == ls.begin()) {
                break;
            }
            --it;
            it = ls.erase(it);
            ret++;
        }
        return ret;
    }

    string cursorLeft(int k) {
        for (int i = 0; i < k; i++) {
            if (it == ls.begin())
                break;
            --it;
        }
        auto j = it;
        string ret;
        for (int i = 0; i < 10; i++) {
            if (j == ls.begin())
                break;
            --j;
            ret.push_back(*j);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    string cursorRight(int k) {
        for (int i = 0; i < k; i++) {
            if (it == ls.end())
                break;
            ++it;
        }
        auto j = it;
        string ret;
        for (int i = 0; i < 10; i++) {
            if (j == ls.begin())
                break;
            --j;
            ret.push_back(*j);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */