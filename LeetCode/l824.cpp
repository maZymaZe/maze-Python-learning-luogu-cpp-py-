bool ck[300]={false};int cnt;
string f(string& S,int l,int r,int a){
    string ret;
    if(ck[S[l]]==true){
        ret=S.substr(l,r-l)+"ma"; 
    }else{
        ret=S.substr(l+1,r-l-1)+S[l]+string("ma");
    } 
    ret=ret+string(a,'a');
    return ret;
}
class Solution {
public:
    string toGoatLatin(string S) {
        ck['a']=ck['e']=ck['o']=ck['i']=ck['u']=ck['A']=ck['E']=ck['I']=ck['O']=ck['U']=true;
        int len=S.size();cnt=0;
        for(int i=0;i<len;i++)if(S[i]==' ')cnt++;
        if(cnt==0){
            return f(S,0,len,1);
        }
        string ans;int slow,fast,t=1;
        for(int i=0;i<len;i++)if(S[i]==' '){
            ans=f(S,0,i,1);slow=fast=i+1;break;
        }
        while(fast<len){
            while(fast<len&&S[fast]!=' ')fast++;
            t++;
            ans=ans+" "+f(S,slow,fast,t);
            slow=++fast;
        }
        return ans;
    }
};