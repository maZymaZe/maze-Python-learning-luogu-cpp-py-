class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int cnt=1,l=arr.size();
        vector<int> v(l);
        deque<int> dq;
        dq.push_back(start);
        while(!dq.empty())
        {
            int f=dq.front();
            dq.pop_front();
            if(f+arr[f]<l&&f+arr[f]>=0&&v[f+arr[f]]==0){
                v[f+arr[f]]=1;
                cnt++;
                dq.push_back(f+arr[f]);
            }
            if(f-arr[f]<l&&f-arr[f]>=0&&v[f-arr[f]]==0){
                v[f-arr[f]]=1;
                cnt++;
                dq.push_back(f-arr[f]);
            }
        }
       for(int i=0;i<l;i++){
           if(arr[i]==0&&v[i]==1)return true;
       }
       return false;

    }
};