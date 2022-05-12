class RangeModule {
   private:
    std::map<int, int> M;

   public:
    RangeModule() {}

    ~RangeModule() {}

    void addRange(int left, int right) {
        auto i = M.lower_bound(right);

        if (M.end() != i and i->second <= right) {
            if (i->second <= left)
                return;
            else
                i->second = left;
        } else
            i = M.emplace_hint(i, right, left);

        while (M.begin() != i) {
            auto j = std::prev(i);
            if (j->first >= left) {
                int tmp = j->second;
                M.erase(j);
                if (tmp >= left)
                    continue;
                else
                    i->second = tmp;
            }
            break;
        }
    }

    void removeRange(int left, int right) {
        auto i = M.upper_bound(right);

        if (M.end() != i and i->second < right) {
            if (i->second < left) {
                M.emplace_hint(i, left, i->second);
                i->second = right;
                return;
            }
            i->second = right;
        }

        while (M.begin() != i) {
            auto j = std::prev(i);
            if (j->first > left) {
                int tmp = j->second;
                M.erase(j);
                if (tmp >= left)
                    continue;
                else
                    M.emplace_hint(i, left, tmp);
            }
            break;
        }
    }

    bool queryRange(int left, int right) {
        auto i = M.lower_bound(right);
        return M.end() != i and i->second <= left;
    }
};
