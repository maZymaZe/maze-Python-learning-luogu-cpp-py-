class Solution {
public:
    bool f(char x){
        return x=='a'||x=='e'||x=='i'||x=='o'||x=='u'
        ||x=='A'||x=='E'||x=='I'||x=='O'||x=='U';
    }
    string reverseVowels(string s) {
        int l= s.size();
        int p=0,q=l-1;
        while(p<q){
            while(p<q&&!f(s[p]))p++;
            while(p<q&&!f(s[q]))q--;
            if(p<q)swap(s[p],s[q]);
            p++,q--;
        }
        return s;
    }
};