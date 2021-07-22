class Solution {
public:
    string interpret(string command) {
        string ans;
        int l=command.size();
        for (int i=0; i<l; i++) {
            if(command[i]!='('&&command[i]!=')' )
            ans+=command[i];
            else if(command[i]==')'&&command[i-1]=='(')
            ans+='o';
        }
        return ans;
    }
};