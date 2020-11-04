public class Solution {
    public IList<string> BuildArray(int[] target, int n) {
        int p=0,l=target.Length;
        string pus="Push",po="Pop";
        IList<string> ans = new List<string>{};
        for(int i = 1; i <= n; i++)
        {
            if (target[p] == i)
            {
                ans.Add(pus);
                p++;
            }
            else
            {
                ans.Add(pus);
                ans.Add(po);
            }
            if(p==l)break;
        }
        return ans;

    }
}