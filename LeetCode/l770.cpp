class Solution {
   private:
    // 字符串到对应数字的映射： 针对evalvars 和 evalints
    unordered_map<string, int> str2val;

    // 自定义的减法实现:全部都需要按照字符串到数值做映射来实现
    map<string, int> sub(map<string, int>& a, map<string, int>& b) {
        map<string, int> res = a;
        for (auto iter = b.begin(); iter != b.end(); ++iter) {
            res[iter->first] -= iter->second;
        }
        return res;
    }

    // 自定义的加法实现
    map<string, int> add(map<string, int>& a, map<string, int>& b) {
        map<string, int> res = a;
        for (auto iter = b.begin(); iter != b.end(); ++iter) {
            res[iter->first] += iter->second;
        }
        return res;
    }

    // 自定义的乘法实现
    map<string, int> mul(map<string, int>& aa, map<string, int>& bb) {
        // 对于常量我们用一个特殊字符 # 来表示
        map<string, int> res;
        res["#"] = 0;
        for (auto& a : aa) {
            for (auto& b : bb) {
                // 有常数，就可以直接乘上去累加即可
                if (a.first == "#") {
                    res[b.first] += a.second * b.second;
                } else if (b.first == "#") {
                    res[a.first] += a.second * b.second;
                } else {
                    // b不是常数，需要去合成新的变量
                    string newVar = combineNewVar(a.first, b.first);
                    res[newVar] += a.second * b.second;
                }
            }
        }
        return res;
    }

    // b*c*e * a*d -> a*b*c*d*e
    string combineNewVar(string a, string b) {
        vector<string> A;

        a += "*";
        int pos = a.find("*", 0);
        // 找出每个*分隔插入到数组里,  如 a*b*c -> [a, b, c]
        while (pos != a.npos) {
            A.push_back(a.substr(0, pos));
            a = a.substr(pos + 1, a.size());
            pos = a.find("*", 0);
        }

        // 同样做拆分
        b += "*";
        pos = b.find("*", 0);
        while (pos != a.npos) {
            A.push_back(b.substr(0, pos));
            b = b.substr(pos + 1, b.size());
            pos = b.find("*", 0);
        }

        // 这里做了排序，否则结果会过不了
        sort(A.begin(), A.end());

        // 构建结果
        string res = A[0];
        for (int i = 1; i < A.size(); ++i) {
            res += "*" + A[i];
        }
        return res;
    }

    // 获取下一个操作数
    map<string, int> next(string& str, int& index) {
        map<string, int> res;
        res["#"] = 0;
        int n = str.size();
        if (index >= n) {
            return res;
        }

        int start = index;
        if (str[index] == '(') {
            // 取出() 里包含的，可能里面包含多个(()())以最外围为准
            stack<int> s;
            s.push(str[index]);
            ++index;
            while (index < n && !s.empty()) {
                if (str[index] == '(') {
                    s.push(index);
                } else if (str[index] == ')') {
                    s.pop();
                }
                ++index;
            }
            // 不包含外围的()两个字符
            // cout << "next () " << str.substr(start+1, index-start-2) << endl;
            res = calculate(str.substr(start + 1, index - start - 2));
        } else if (str[index] >= '0' && str[index] <= '9') {
            // 取出连续的数字来，并且填充到#对应key里
            while (index < n && str[index] >= '0' && str[index] <= '9') {
                ++index;
            }
            res["#"] = stoi(str.substr(start, index - start));
        } else {
            // 一个变量的情况
            while (index < n && str[index] != ' ') {
                ++index;
            }
            string curr = str.substr(start, index - start);
            if (str2val.find(curr) != str2val.end()) {
                res["#"] = str2val[curr];
            } else {
                // 变量默认值就是1
                res[curr] = 1;
            }
        }
        ++index;
        return res;
    }

    // 基于新元素的计算器
    map<string, int> calculate(string str) {
        // cout << "calculate " << str << endl;
        map<string, int> res;
        if (str.empty()) {
            return res;
        }
        map<string, int> currRes;
        res["#"] = 0;
        currRes["#"] = 0;
        str += " +";
        int n = str.size();
        char op = '+';

        for (int i = 0; i < n; i += 2) {
            map<string, int> x = next(str, i);
            if (str[i] == '+' || str[i] == '-' || str[i] == '*' || i == n - 1) {
                if (op == '+') {
                    currRes = add(currRes, x);
                } else if (op == '-') {
                    currRes = sub(currRes, x);
                } else if (op == '*') {
                    currRes = mul(currRes, x);
                }

                if (str[i] == '+' || str[i] == '-' || i == n - 1) {
                    res = add(res, currRes);
                    currRes.clear();
                    currRes["#"] = 0;
                }

                op = str[i];
            }
        }

        return res;
    }

   public:
    vector<string> basicCalculatorIV(string expression,
                                     vector<string>& evalvars,
                                     vector<int>& evalints) {
        // 哈希表记录已知映射关系
        for (int i = 0; i < evalvars.size(); ++i) {
            str2val[evalvars[i]] = evalints[i];
        }

        map<string, int> maps = calculate(expression);

        // 后处理
        // - 把常量存放在前面
        // - 变量越多，约靠前，所以这里会有一个cnt
        vector<pair<int, string>> sorted;
        for (auto& m : maps) {
            if (m.second != 0 && m.first != "#") {
                string str = m.first + "*";
                int cnt = 0;
                int pos = str.find("*", 0);
                while (pos != str.npos) {
                    ++cnt;
                    str = str.substr(pos + 1, str.size());
                    pos = str.find("*", 0);
                }
                sorted.push_back({cnt, m.first});
            }
        }
        // 排序是优先cnt（变量数量的降序），然后才是字符串数字
        sort(sorted.begin(), sorted.end(),
             [](const pair<int, string>& a, const pair<int, string>& b) {
                 return a.first != b.first ? a.first > b.first
                                           : a.second < b.second;
             });

        vector<string> res(sorted.size());

        for (int i = 0; i < sorted.size(); ++i) {
            res[i] = to_string(maps[sorted[i].second]) + "*" + sorted[i].second;
        }

        // 最后插入常量
        if (maps["#"] != 0) {
            res.push_back(to_string(maps["#"]));
        }
        return res;
    }
};
