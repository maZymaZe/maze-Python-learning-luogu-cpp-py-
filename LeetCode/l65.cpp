class Solution {
   public:
    bool isInteger(string s) {
        int l = s.size();
        if (l == 0)
            return false;
        if (l == 1)
            return s[0] <= '9' && s[0] >= '0';
        int p = 0;
        if (s[p] == '+' || s[p] == '-')
            p++;
        while (p < l)
            if (s[p] > '9' || s[p] < '0')
                return false;
            else
                p++;
        return true;
    }
    bool isFloat(string s) {
        int l= s.size();
        if(l<2)return false;
        int p = 0;
        if(s[p] == '+' || s[p] == '-')p++;
        int d=p;
        while(d<l){
            if(s[d] == '.')break;
            else d++;
        }
        if(d==l)return false;
        if(d==l-1){
            int f=0;
            while(p<d){
                if(s[p] >= '0' && s[p] <= '9'){
                    f=1,p++;
                }else return false;
            }
            return f;
        }else if(d==p){
            int f=0;
            p++;
            while (p<l){
                if(s[p] >= '0' && s[p]<= '9'){
                    f=1,p++;
                }else return false;
            }
            return f;
        }
        while(p<d){
            if(s[p] >= '0' && s[p] <= '9')p++;
            else return false;
        }
        p=d+1;
        while(p<l){
            if(s[p] >= '0' && s[p] <= '9')p++;
            else return false;
        }
        return true;
    }
    bool isNumber(string s) {
        int l = s.size();
        for (int i = 0; i < l; i++) {
            if (s[i] == 'E' || s[i] == 'e') {
                if (i!=0&&i!=l-1) {
                    return (isInteger(s.substr(i + 1, s.size()))) &&
                           (isFloat(s.substr(0, i)) ||
                            isInteger(s.substr(0, i)));
                } else
                    return 0;
            }
        }
        return isInteger(s) || isFloat(s);
    }
};