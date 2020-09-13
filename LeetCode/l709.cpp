class Solution {
public:
    string toLowerCase(string str) {
        char t[3000]={0};
        for (int i=str.size();i>=0;i--){
            if(str[i]>='A'&&str[i]<='Z')t[i]=str[i]-'A'+'a';
            else t[i]=str[i]; 
        }
        return string(t);

    }
};