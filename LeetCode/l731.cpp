
class MyCalendarTwo {
   public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        for (const auto& i : s2) {
            if (start >= i.second || end <= i.first) {
                continue;
            }
            return false;
        }

        for (const auto& i : s1) {
            if (start >= i.second || end <= i.first) {
                continue;
            }
            s2.insert(make_pair(max(start, i.first), min(end, i.second)));
        }

        s1.insert(make_pair(start, end));
        return true;
    }

   private:
    set<pair<int, int>> s1;  // interval pairs that have 1 overlappings
    set<pair<int, int>> s2;  // interval pairs that have 2 overlappings
};
