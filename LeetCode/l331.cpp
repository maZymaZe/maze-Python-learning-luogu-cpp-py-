class Solution {
   public:
    stack<int> s;
    bool isValidSerialization(string preorder) {
        s.push(1);
        preorder += ",";
        int len = preorder.length();
        for (int i = 0; i < len; i++) {
            if (preorder[i] == ',') {
                if (s.empty())
                    return false;
                s.top()--;
                if (s.top() == 0)
                    s.pop();
                if (preorder[i - 1] != '#') {
                    s.push(2);
                }
            }
        }
        return s.empty();
    }
};