class Solution {
   public:
    string getSmallestString(string s, int k) {
        int l=s.size();
        for(int i=0; i<l; i++){
            if(k==0)return s;
            int t1=s[i]-'a',t2='z'+1-s[i];
            if(min(t1,t2)<=k){
                s[i]='a';
                k-=min(t1,t2);
            }else{
                s[i]-=k;
                k=0;
            }
        }
        return s;
    }
};