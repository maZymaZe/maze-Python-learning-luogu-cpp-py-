class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        char a[103]={0};
        int l=s.size();
        for(int i=0;i<l;i++){
            a[indices[i]]=s[i];
        }
        return string(a);
    }
};