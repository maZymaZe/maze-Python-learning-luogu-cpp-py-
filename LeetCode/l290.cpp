class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        int ll=pattern.size(),p=0,l=s.size();
        for(int i=0; i< l; i++){
            if(s[i]==' '){
                words.push_back(s.substr(p,i-p));
                p=i+1;
            }
        }
        words.push_back(s.substr(p,l-p));
        string mp[26];
        unordered_set<string> st;
        
        if(words.size()!=ll)return false;
        for(int i=0;i<ll;i++){
            if(mp[pattern[i]-'a']==""&&!st.count(words[i])){
                mp[pattern[i]-'a']=words[i],st.insert(words[i]);
            }else if(mp[pattern[i]-'a']!=words[i])return false;
        }
        return true;
    }
};