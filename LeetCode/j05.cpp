class Solution {
public:
    string replaceSpace(string s) {
        string S;
        for(auto c:s){
            if(c!=' ')S+=c;
            else S+="%20";
        }
        return S;
    }
};