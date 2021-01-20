class Solution {
public:
    static bool cmp(const string&a,const string&b){
        return (a+b)<(b+a);
    }
    string minNumber(vector<int>& nums) {
        vector<string> s;
        for(int i:nums)s.push_back(to_string(i));
        string ans;
        sort(s.begin(),s.end(),cmp);
        for(string &i:s)ans+=i;
        return ans;
    }
};