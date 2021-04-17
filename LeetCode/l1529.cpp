class Solution {
public:
    int minFlips(string target) {
        int l=target.size(),n=0,ans=0,f=0;
        for(int i=0;i<l;i++){
            if(f==0&&target[i]=='1'){
                f=1;
                n='1';
                ans=1;
            }
            else if(f==1&&target[i]!=n){
                ans++;
                n^=1;
            }
        }
        return ans;
    }
};