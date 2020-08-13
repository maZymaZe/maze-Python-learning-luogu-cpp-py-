class Solution {
public:
    bool isValid(string s) {
        if(s.empty())return true;
        stack<char> t;
        for(auto i:s){
            if(i=='('||i=='{'||i=='[')t.push(i);
            if(i==']'){
                if(t.empty())return false;
                if(t.top()=='[')t.pop();
                else return false;
            }
            if(i==')'){
                if(t.empty())return false;
                if(t.top()=='(')t.pop();
                else return false;
            }
            if(i=='}'){
                if(t.empty())return false;
                if(t.top()=='{')t.pop();
                else return false;
            }
        }
        return t.empty();
    }
};