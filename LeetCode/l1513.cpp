class Solution {
public:
    long long tot=0;
    void query(long long x){
        tot+=(1+x)*x/2;
    } 
    int numSub(string s) {
        long long cnt=0,l=s.size();
        for(int i=0;i<l;i++){
            if(s[i]=='0'){
                query(cnt);
                cnt=0;
            }else{
                cnt++;
            }
        }
        query(cnt);
        return tot%1000000007;
    }
};