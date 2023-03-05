class Solution {
   public:
    int minimumDeletions(string s) {
        int l = s.size(), c = 0;
        for (char ch : s)
            c += (ch == 'a');
        int ans = c;
        for (char ch : s) {
            if (ch == 'a')
                c--;
            else
                c++;
            ans = min(ans, c);
        }
        return ans;
    }
};