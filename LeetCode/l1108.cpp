class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for(auto c:address){
            if(c=='.')ans+="[.]";
            else ans+=c;
        }
        return ans;
    }
};