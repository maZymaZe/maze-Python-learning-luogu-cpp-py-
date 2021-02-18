class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ret(num_people);
        int p=1,pos=0;
        while (candies){
            if(candies>=p)ret[pos++]+=p,candies-=p;
            else ret[pos++]+=candies,candies=0;
            if(pos==num_people)pos=0;
            p++;
        }
        return ret;
    }
};