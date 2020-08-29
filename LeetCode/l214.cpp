class Solution {
public:
    string shortestPalindrome(string s) {
        int l=s.size(),ml,mr,ll;
        string cg("*#");
        for(int i=0; i<l; i++){
            cg += s[i];
            cg+='#';
        }
        ll=2*l+1;
        vector<int> p(l+2);
        int mid=1,mx=1,ans=0;
        for(int i=1;i<=l+1;i++){
            if(i<mx)p[i]=min(mx-i,p[2*mid-i]);
            else p[i]=1;
            while(cg[i+p[i]]==cg[i-p[i]])p[i]++;
            if(mx<i+p[i]){
                mid=i;
                mx=i+p[i];
            }
            if(i-p[i]==0){
                ans=i-1;
            }
        }
        string t=s.substr(ans,l);
        reverse(t.begin(),t.end());
        return t+s;
        
    }
};