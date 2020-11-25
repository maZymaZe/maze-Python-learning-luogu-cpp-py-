public class Solution {
    public int FindContentChildren(int[] g, int[] s) {
        int pg=0,ps=0,lg=g.Length,ls=s.Length,cnt=0;
        Array.Sort(g);Array.Sort(s);
        while(pg<lg&&ps<ls){
            if(s[ps]>=g[pg]){ps++;pg++;cnt++;}
            else ps++;
        }
        return cnt;
    }
}