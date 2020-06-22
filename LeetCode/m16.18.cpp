class Solution {
public:
    bool patternMatching(string pattern, string value) {
        int ca=0,cb=0;
        for(char c:pattern)
        if(c=='a')ca++;
        else cb++;
        if(ca<cb){
            swap(ca,cb);
            for(char &c:pattern)
            c=(c=='a')?'b':'a';
        }
        if(value.empty())return cb==0;
        if(pattern.empty())return false;
        for(int la=0;ca*la<=value.size();la++){
            int res=value.size()-ca*la;
            if((cb==0&&res==0)||(cb!=0&&res%cb)==0){
                int lb=(cb==0)?0:res/cb;
                int p=0;
                bool f=true;
                string a,b;
                for(char c:pattern){
                    if(c=='a'){
                        string s=value.substr(p,la);
                        if(a.empty())a=move(s);
                        else if(a!=s){
                            f=false;
                            break;
                        }
                        p+=la;
                    }
                    else{
                        string s=value.substr(p,lb);
                        if(b.empty())b=move(s);
                        else if(b!=s){
                            f=false;
                            break;
                        }
                        p+=lb;
                    }
                }
                if(f&&a!=b)return true;
            }
        }
        return false;
    }
};