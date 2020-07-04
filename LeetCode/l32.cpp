class Solution {
public:
    int longestValidParentheses(string s) {
        vector<bool> vec(s.size());
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(i);
            else{
                if(st.empty())vec[i]=true;
                else st.pop();
            }
        }
        while(!st.empty()){
            vec[st.top()]=true;
            st.pop();
        }
        int cnt=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(vec[i]){
                ans=max(ans,cnt);
                cnt=0;
            }
            else{
                cnt++;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};