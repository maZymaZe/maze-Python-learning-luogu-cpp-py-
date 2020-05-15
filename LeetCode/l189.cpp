class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        int count=0,l=nums.size();
        for(int i=0;count<l;i++){
            int tmp=i,tmpv=nums[i];
            do{
                int nx=(tmp+k)%l;
                int tnx=nums[nx];
                nums[nx]=tmpv;
                tmp=nx;
                tmpv=tnx;
                count++;
            }while(tmp!=i);
        }
    }
};