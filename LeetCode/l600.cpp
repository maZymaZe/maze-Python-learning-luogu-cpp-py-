class Solution {
public:
    int f[35][2]; 
    int findIntegers(int num) {
        f[0][0]=1;
        for(int i=1;i<35;i++){
            f[i][0]=f[i-1][0]+f[i-1][1];
            f[i][1]=f[i-1][0];
        }
        vector<int> nums;
        while(num){
            nums.push_back(num&1);
            num>>=1;
        }
        int res=0,lst=0;
        for(int i=nums.size()-1;i>=0;i--){
            int x=nums[i];
            if(x){
                res+=f[i+1][0];
                if(x&&lst)break;
            }
            lst=x; 
            if(!i)res++;
        }
       
        return res;
    }
    
};