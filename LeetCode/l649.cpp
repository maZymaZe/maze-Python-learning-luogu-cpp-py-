class Solution {
   public:
    string predictPartyVictory(string senate) {
        int l = senate.size();
        queue<int> r, d;
        for (int i = 0; i < l; i++) {
            if (senate[i] == 'R')
                r.push(i);
            else d.push(i);
        }
       
        while (!r.empty() && !d.empty()) {
            if(r.front()<d.front())r.push(r.front()+l);
            else d.push(d.front()+l);
            r.pop();
            d.pop();
        } 
        return r.empty()?"Dire":"Radiant";  
    }
};