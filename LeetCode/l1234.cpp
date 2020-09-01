class Solution {
public:
    int balancedString(string s) {
        int mp[300]={0},c[300]={0};
        int l=s.size();
        for(int i=0;i<l;i++)mp[s[i]]++;
        int nd=l/4,ans=l;
        if(mp['Q']==nd&&mp['W']==nd&&mp['E']==nd&&mp['R']==nd)return 0;
        else{
            mp['Q']=(mp['Q']>nd)?mp['Q']-nd:0;
            mp['W']=(mp['W']>nd)?mp['W']-nd:0;
            mp['E']=(mp['E']>nd)?mp['E']-nd:0;
            mp['R']=(mp['R']>nd)?mp['R']-nd:0;
        }
        int ll=0,rr=0;
        while(rr<l){
            while(rr<l&&!(c['Q']>=mp['Q']&&c['R']>=mp['R']&&c['E']>=mp['E']&&c['W']>=mp['W'])){
                c[s[rr]]++;
                rr++;
            }
            while(ll<l&&(c['Q']>=mp['Q']&&c['R']>=mp['R']&&c['E']>=mp['E']&&c['W']>=mp['W'])){
                c[s[ll]]--;
                ll++;
            }
            if(rr-ll+1<ans)ans=rr-ll+1;
        }
        return ans;
    }
};