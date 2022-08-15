class Solution {
   public:
    int findString(vector<string>& words, string s) {
        int l = words.size();
        int ll = 0, rr = l - 1;
        while (ll <= rr) {
            while (ll <= rr && words[ll].size() == 0)
                ll++;
            while (ll <= rr && words[rr].size() == 0)
                rr--;
            int mid = (ll + rr) / 2;
            while (mid <= rr && words[mid].size() == 0)
                mid++;
            if (words[mid] == s)
                return mid;
            if (words[mid] > s)
                rr = mid - 1;
            else
                ll = mid + 1;
        }
        return -1;
    }
};