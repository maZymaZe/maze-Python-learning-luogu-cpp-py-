class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        char t[120]={0};
        int p=0,l;
        unordered_set<string> s;
        for(auto i:emails){
            p=0;l=i.size();
            memset(t,0,sizeof(t));
            for(int j=0;j<l;j++){
                if(i[j]=='+'){
                    while(i[j]!='@')j++;
                }
                if(i[j]=='@'){
                    s.insert(string(t)+i.substr(j,l));
                    break;
                }
                if(i[j]!='.')t[p++]=i[j];
            }
        }
        return s.size();
    }
};