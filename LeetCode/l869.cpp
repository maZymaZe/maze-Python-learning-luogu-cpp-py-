class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string s=to_string(N);
        sort(s.begin(),s.end());
        int l=s.length();
        if(l==1){
            return s=="1"||s=="2"||s=="4"||s=="8";
        }else if(l==2){
            return s=="16"||s=="23"||s=="46";
        }else if(l==3){
            return s=="128"||s=="256"||s=="125";
        }else if(l==4){
            return s=="0124"||s=="0248"||s=="0469"||s=="1289";
        }else if(l==5){
            return s=="13468"||s=="23678"||s=="35566";
        }else if(l==6){
            return s=="011237"||s=="122446"||s=="224588";
        }else if(l==7){
            return s=="0145678"||s=="0122579"||s=="0134449"||s=="0368888";
        }else if(l==8){
            return s=="11266777"||s=="23334455"||s=="01466788";
        }else if(l==9){
            return s=="112234778"||s=="234455668"||s=="012356789";
        }
        return false;
    }
};