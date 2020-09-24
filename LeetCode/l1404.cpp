class Solution {
public:
    int numSteps(string s) {
        int l=s.size();
        int ans=0;
        bool meet1=false;
        for(int i=l-1; i>=0; i--){
            if(s[i]=='0')ans+=(meet1?2:1);
            else{
                if(!meet1){
                    if(i!=0)ans+=2;
                    meet1=true;
                }else ans++;
            }
        }
        return ans;
    }
};