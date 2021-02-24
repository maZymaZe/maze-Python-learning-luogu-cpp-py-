class Solution {
public:
    static bool cmp(const string& a, const string& b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(int i:nums)v.push_back(to_string(i));
        sort(v.begin(),v.end(),cmp);
        string ans;
        for(const string& i:v)ans+=i;
        if(ans[0]=='0')return "0";
        return ans;
    }
};