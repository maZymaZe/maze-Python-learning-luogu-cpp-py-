class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s;
        for (int i : nums)
            s.insert(i);
        int mx = 0;
        for (int i : nums)
        {
            if (s.count(i - 1) == 0)
            {
                int l = 1, now = i + 1;
                while (s.count(now))
                    l++, now++;
                mx = max(mx, l);
            }
        }
        return mx;
    }
};