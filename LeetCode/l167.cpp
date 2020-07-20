class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=numbers.size(),fast=l-1,slow=0;
        while(numbers[fast]+numbers[slow]!=target){
            if(numbers[fast]+numbers[slow]>target)fast--;
            else slow++;
        }
        return vector<int>() ={slow+1,fast+1};
    }
};