class Solution {
   public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string track = "";
        backtrack(num, target, 0, 0, 1, result, track);
        return result;
    }
    //注：mult表示的上一步的操作数
    void backtrack(string num,
                   int target,
                   int index,
                   long val,
                   long mult,
                   vector<string>& result,
                   string& track) {
        if (index == num.size()) {
            if (val == target)
                result.push_back(track);
            return;
        }
        int len = track.size();
        for (int i = index; i < num.length(); i++) {
            //转换数字
            string sVal = num.substr(index, i - index + 1);
            long n = stol(sVal);
            //第一个数字，不需要加符号
            if (index == 0) {
                track += sVal;
                backtrack(num, target, i + 1, n, n, result, track);
                track.resize(len);
            } else {
                // +
                track += "+" + sVal;
                backtrack(num, target, i + 1, val + n, n, result, track);
                track.resize(len);
                // -
                track += "-" + sVal;
                backtrack(num, target, i + 1, val - n, -n, result, track);
                track.resize(len);
                // *
                track += "*" + sVal;
                //由于乘法的优先级比加、减法高，所以需要回退到上一步，即把上一步的操作数与乘法进行运算
                //比如2+3*2，我们在3后面添加*，然而*的优先级高，所以val(5)-mult(3)返回上一步，然后2+3*2=8
                backtrack(num, target, i + 1, val - mult + mult * n, mult * n,
                          result, track);
                track.resize(len);
            }
            if (n == 0)
                return;
        }
    }
};
