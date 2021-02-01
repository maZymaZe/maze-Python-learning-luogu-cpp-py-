class Solution {
public:
    string replaceSpaces(string S, int length) {
        int p=length;
        for(int i=0; i<length; i++){
            if(S[i]==' ')p++;
        }
        p--;
        for(int i=length-1;i>=0;i--){
            if(S[i]==' '){
                S[p--]='0';
                S[p--]='2';
                S[p--]='%';
            }else S[p--]=S[i];
        }
        return S;
    }
};