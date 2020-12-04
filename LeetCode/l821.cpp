class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int l=S.length();
        set<int> s;
        s.insert(-40000),s.insert(40000);
        for(int i=0;i<l;i++)if(S[i]==C)s.insert(i);
        vector<int> result(l);
        for(int i=0;i<l;i++){
            auto x=s.lower_bound(i);
            result[i]=(*x)-i;
            --x;
            if(i-*x<result[i])result[i]=i-*x;
        }
        return result;
    }
};