class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int l=startTime.size(),cnt=0;
        for(int i=0;i<l;i++){
            if(startTime[i]<=queryTime&&endTime[i]>=queryTime)cnt++;
        }
        return cnt;
    }
};