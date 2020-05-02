class Solution {
public:
    int maxScore(string s) {
        int s1,m=0,l=s.size(),t;
        s1=count(s.begin(),s.end(),'1');
        if(s[0]=='0')t=s1+1;
        else t=s1-1;
        m=t;
        for(int i=1;i<l-1;i++){
            if(s[i]=='0'){
                t++;
                m=max(m,t);
            }
            else{
                t--;
            }
        }
        return m;
    }
};