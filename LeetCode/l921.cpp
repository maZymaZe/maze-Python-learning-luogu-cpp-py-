class Solution {
public:
    int minAddToMakeValid(string S) {
        int l= S.size(),cnt=0,ans=0;
        for(int i=0;i<l;i++){
            if(S[i]=='('){
                cnt++;
            }
            else{
                if(cnt)cnt--;
                else ans++;
            }
        }
        return cnt+ans;        
    }
};