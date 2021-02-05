/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        int l=s.size();
        NestedInteger a;
        stack<NestedInteger> k;
        if(s[0]=='['){
            k.push(a);
            int rs=0,f=1;
            for(int i=1;i<l-1;i++){
                if((s[i]>='0'&&s[i]<='9')||s[i]=='-'){
                    if(s[i]=='-')f=-1,i++;
                    while(s[i]>='0'&&s[i]<='9'){
                        rs=rs*10+s[i]-'0';
                        i++;
                    }
                    rs*=f;
                    k.top().add(NestedInteger(rs));
                    rs=0,f=1;
                    i--;
                }
                if(s[i]=='['){
                    k.push(NestedInteger());
                }
                if(s[i]==']'){
                    NestedInteger t=k.top();
                    k.pop();
                    k.top().add(t);
                }

            }
            return k.top();
        }else{
            int p=0,f=1,rs=0;
            if(s[0]=='-')f=-1,p++;
            for(int i=p;i<l;i++){
                rs=rs*10+s[i]-'0';
            }
            a.setInteger(rs*f);
            return a;
        }
        return a;
    }
};