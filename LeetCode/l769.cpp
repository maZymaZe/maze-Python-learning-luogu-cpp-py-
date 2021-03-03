class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int l=arr.size();
        vector<int> mp(l);
        int umc=0,ans=0;
        for(int i=0;i<l;i++){
            if(mp[arr[i]])mp[arr[i]]=0,umc--;
            else mp[arr[i]]=1,umc++;
            if(mp[i])mp[i]=0,umc--;
            else mp[i]=1,umc++;
            if(umc==0)ans++;
        }
        return ans;
    }
};