class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;
        int a[55]={0};
        int tot=0,ans=0,l=S.size();
        for(int i=0;i<l;i++){
            if(S[i]=='(')s.push(i);
            if(S[i]==')'){
                if(i-s.top()==1){
                    s.pop(),a[s.size()]+=1;
                }
                else{
                    a[s.size()-1]+=a[s.size()]*2;
                    a[s.size()]=0;
                    s.pop();
                }
            }
        }
        return a[0];
    }
};