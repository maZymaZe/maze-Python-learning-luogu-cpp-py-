class Solution {
public:
    int tribonacci(int n) {
        long long a=0,b=1,c=1;
        while(n--){
            a+=b+c;
            swap(a,b);
            swap(b,c);
        }
        return a;
    }
};