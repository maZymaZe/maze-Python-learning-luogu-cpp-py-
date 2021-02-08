class Solution {
public:
    bool myisdigit(char x){return (x >= '0' && x <= '9');}
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n);
        stack<int> id,st;
        int m=logs.size();
        for (int i=0; i<m; i++){
            int p=0,d=0,l=logs[i].size(),f=0,t=0;
            while(myisdigit(logs[i][p]))d=d*10+logs[i][p]-'0',p++;
            if(logs[i][p+1]=='s')f=0;
            else if(logs[i][p+1]=='e')f=1;
            while(!myisdigit(logs[i][p]))p++;
            while(p<l&&myisdigit(logs[i][p]))t=t*10+logs[i][p]-'0',p++;
            if(f){
                res[id.top()]+=(t-st.top()+1);
                id.pop();
                st.pop();
                if(!st.empty())st.pop(),st.push(t+1);
            }else{
                if(!id.empty()){
                    res[id.top()]+=(t-st.top());
                }
                id.push(d);st.push(t);
            }
        }
        return res;
    }
};