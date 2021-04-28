class Solution {
public:
    string reformat(string s) {
        vector<char> n,l;
        for(auto ch:s){
            if(ch>='0' && ch<='9')n.push_back(ch);
            else l.push_back(ch);
        }
        int ll=l.size(),ln=n.size();
        if(ln==ll){
            string st;
            for(int i=0;i<ll;i++){
                st.push_back(n[i]);
                st.push_back(l[i]);
            }
            return st;
        }
        if(ln==ll+1){
            string st;
            for(int i=0;i<ll;i++){
                st.push_back(n[i]);
                st.push_back(l[i]);
            }
            st.push_back(n[ll]);
            return st;
        }
        if(ln+1==ll){
            string st;
            for(int i=0;i<ln;i++){
                st.push_back(l[i]);
                st.push_back(n[i]);
            }
            st.push_back(l[ln]);
            return st;
        }
        return "";
    }
};