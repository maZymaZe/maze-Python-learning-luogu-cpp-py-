bool isn(char c) {
    return (c >= '0' && c <= '9');
}
class StringIterator {
   public:
    string::iterator it, ee;
    char nw;
    int count;
    int hn;
    string my;
    StringIterator(string compressedString) {
        my = compressedString;
        it = my.begin();
        ee = my.end();
        hn = 0;
        if (it != ee) {
            hn = 1;
            nw = *it;
            ++it;
            int t = *it - '0';
            ++it;
            while (it != ee && isn(*it))
                t = t * 10 + *it - '0', ++it;
            count = t;
        }
    }

    char next() {
        if (!hn)
            return ' ';
        char ret = nw;
        count--;
        if (count == 0) {
            if (it != ee) {
                hn = 1;
                nw = *it;
                ++it;
                int t = *it - '0';
                ++it;
                while (it != ee && isn(*it))
                    t = t * 10 + *it - '0', ++it;
                count = t;
            } else
                hn = 0;
        }
        return ret;
    }

    bool hasNext() { return hn; }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */