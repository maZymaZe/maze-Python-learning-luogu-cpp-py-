class Solution {
public:
    int maxPower(string s) {
        int ans=1,cnt=0;
        char pre='#';
        for(char i:s){
            if(i==pre){
                cnt++;
                if(cnt>ans)ans=cnt;
            }else{
                pre=i;
                cnt=1;
            }
        }
        return ans;
    }
};