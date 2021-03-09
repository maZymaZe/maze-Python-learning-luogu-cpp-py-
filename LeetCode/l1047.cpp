class Solution {
public:
    list<char> ls;
    string removeDuplicates(string S) {
        for(char i:S)ls.push_back(i);
        auto p=ls.begin();
        while(p!=ls.end()){
            auto pp=p;p++;
            if(*pp==*p){
                pp=ls.erase(pp);
                pp=ls.erase(pp);
                p=pp;
                if(p!=ls.begin()){
                    p--;
                }
            }
        }
        string ans;
        for(char i:ls)ans+=i;
        return ans;
    }
};