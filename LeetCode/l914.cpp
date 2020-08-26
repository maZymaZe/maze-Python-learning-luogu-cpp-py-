class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> mp;
        vector<int> v;
        for(int &i:deck){
            if(mp.count(i))mp[i]++;
            else{
                mp.insert({i,1});
                v.push_back(i);
            }
        }
        int l=v.size();
        if(!l)return false;
        int w=mp[v[0]];
        for(int i=1;i<l;i++)w=__gcd(w,mp[v[i]]);
        return w>1;
    }
};