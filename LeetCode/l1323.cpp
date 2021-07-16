class Solution {
public:
    int maximum69Number (int num) {
        string str=to_string(num);
        int l=str.length();
        for(int i=0;i<l;i++){
            if(str[i]=='6'){
                str[i]='9';
                break;
            }
        }
        return stoi(str);
    }
};