struct node {
    int a, b;

    bool operator<(const struct node& other) const {
        if (a != other.a) {
            return a < other.a;
        }

        return b < other.b;
    }
};

bool is_special(set<node>& s, int ii, int jj) {
    if (s.find({ii, jj}) != s.end()) {
        return false;
    }

    int i, j, i1, i2, j1, j2;

    i1 = ii;
    while (s.find({i1 - 1, jj}) != s.end()) {
        i1 -= 1;
    }
    i2 = ii;
    while (s.find({i2 + 1, jj}) != s.end()) {
        i2 += 1;
    }
    if (i2 - i1 + 1 >= 5) {
        return true;
    }

    j1 = jj;
    while (s.find({ii, j1 - 1}) != s.end()) {
        j1 -= 1;
    }
    j2 = jj;
    while (s.find({ii, j2 + 1}) != s.end()) {
        j2 += 1;
    }
    if (j2 - j1 + 1 >= 5) {
        return true;
    }

    i1 = ii, j1 = jj;
    while (s.find({i1 - 1, j1 - 1}) != s.end()) {
        i1 -= 1;
        j1 -= 1;
    }
    i2 = ii, j2 = jj;
    while (s.find({i2 + 1, j2 + 1}) != s.end()) {
        i2 += 1;
        j2 += 1;
    }
    if (i2 - i1 + 1 >= 5) {
        return true;
    }

    i1 = ii, j1 = jj;
    while (s.find({i1 - 1, j1 + 1}) != s.end()) {
        i1 -= 1;
        j1 += 1;
    }
    i2 = ii, j2 = jj;
    while (s.find({i2 + 1, j2 - 1}) != s.end()) {
        i2 += 1;
        j2 -= 1;
    }
    if (i2 - i1 + 1 >= 5) {
        return true;
    }

    return false;
}

vector<node> get_special(set<node>& s1, set<node>& s2) {
    set<node> candi;
    for (auto& v : s1) {
        int a = v.a, b = v.b;
        for (auto& v : vector<node>{{a - 1, b},
                                    {a + 1, b},
                                    {a, b - 1},
                                    {a, b + 1},
                                    {a - 1, b - 1},
                                    {a - 1, b + 1},
                                    {a + 1, b - 1},
                                    {a + 1, b + 1}}) {
            int ii = v.a, jj = v.b;
            if (s1.find({ii, jj}) == s1.end() &&
                s2.find({ii, jj}) == s2.end()) {
                candi.insert({ii, jj});
            }
        }
    }

    vector<node> ans;
    for (auto& v : candi) {
        if (is_special(s1, v.a, v.b)) {
            ans.push_back({v.a, v.b});
            if (ans.size() >= 2) {
                break;
            }
        }
    }

    return ans;
}

bool check(set<node>& s1, set<node>& s2) {
    set<node> candi;
    for (auto& v : s1) {
        int a = v.a, b = v.b;
        for (auto& vv : vector<node>{{a - 2, b},
                                     {a - 1, b},
                                     {a + 2, b},
                                     {a + 1, b},
                                     {a, b - 2},
                                     {a, b - 1},
                                     {a, b + 2},
                                     {a, b + 1},
                                     {a - 2, b - 2},
                                     {a - 1, b - 1},
                                     {a + 2, b + 2},
                                     {a + 1, b + 1},
                                     {a - 2, b + 2},
                                     {a - 1, b + 1},
                                     {a + 2, b - 2},
                                     {a + 1, b - 1}}) {
            int aa = vv.a, bb = vv.b;
            if (s1.find({aa, bb}) == s1.end() &&
                s2.find({aa, bb}) == s2.end()) {
                candi.insert({aa, bb});
            }
        }
    }

    for (auto& v : candi) {
        int a = v.a, b = v.b;
        s1.insert({a, b});

        int cnt = 0;
        bool flag = false;

        for (int ii = -4; ii < 5; ii++) {
            if (flag) {
                break;
            }

            for (int jj = -4; jj < 5; jj++) {
                if (ii == 0 || jj == 0 || abs(ii) == abs(jj)) {
                    int new_a = a + ii, new_b = b + jj;
                    if (s1.find({new_a, new_b}) == s1.end() &&
                        s2.find({new_a, new_b}) == s2.end() &&
                        is_special(s1, new_a, new_b)) {
                        cnt += 1;
                        if (cnt >= 2) {
                            flag = true;
                            break;
                        }
                    }
                }
            }
        }

        s1.erase({a, b});
        if (flag) {
            return true;
        }
    }

    return false;
}

class Solution {
   public:
    string gobang(vector<vector<int>>& pieces) {
        set<node> bb, ww;

        for (auto& v : pieces) {
            if (v[2] == 0) {
                bb.insert({v[0], v[1]});
            } else {
                ww.insert({v[0], v[1]});
            }
        }

        vector<node> ret = get_special(bb, ww);
        if (ret.size() >= 1) {
            return "Black";
        } else {
            ret = get_special(ww, bb);
            if (ret.size() >= 2) {
                return "White";
            } else if (ret.size() == 1) {
                int a = ret[0].a, b = ret[0].b;
                bb.insert({a, b});

                ret = get_special(bb, ww);
                if (ret.size() >= 2) {
                    return "Black";
                } else {
                    return "None";
                }
            } else {
                if (check(bb, ww)) {
                    return "Black";
                } else {
                    return "None";
                }
            }
        }
    }
};
