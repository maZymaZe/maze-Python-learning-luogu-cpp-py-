#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool canReorderDoubled(vector<int>& arr) {
        int l = arr.size();
        map<int, int> mp;
        for (int i = 0; i < l; i++) {
            if (arr[i] >= 0)
                mp[arr[i]]++;
        }
        while (!mp.empty()) {
            auto it = mp.begin();
            if (it->first == 0) {
                if (it->second > 1) {
                    mp[0] -= 2;
                    if (mp[0] == 0)
                        mp.erase(0);
                } else
                    return false;
            } else if (it->first != 0 && mp.count(it->first * 2)) {
                mp[it->first * 2]--;
                mp[it->first]--;

                if (mp[it->first * 2] == 0)
                    mp.erase(it->first * 2);
                if (mp[it->first] == 0)
                    mp.erase(it->first);
            } else
                return false;
        }
        for (int i = 0; i < l; i++) {
            if (arr[i] < 0)
                mp[-arr[i]]++;
        }
        while (!mp.empty()) {
            auto it = mp.begin();
            if (mp.count(it->first * 2)) {
                mp[it->first * 2]--;
                mp[it->first]--;

                if (mp[it->first * 2] == 0)
                    mp.erase(it->first * 2);
                if (mp[it->first] == 0)
                    mp.erase(it->first);
            } else
                return false;
        }
        return true;
    }
};
int main() {
    vector<int> a{4, 2, -2, -4};
    Solution().canReorderDoubled(a);
}