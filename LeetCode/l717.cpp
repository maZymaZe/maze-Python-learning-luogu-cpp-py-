class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int l=bits.size(),p=0;
        while(p+1<l){
            if(bits[p])p+=2;
            else p++;
        }
        return p<l;
    }
};