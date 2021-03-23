/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<vector<NestedInteger>::iterator> sn,se;
    NestedIterator(vector<NestedInteger> &nestedList) {
        sn.push(nestedList.begin());
        se.push(nestedList.end());
    }
    
    int next() {
        return sn.top()++->getInteger();
    }
    
    bool hasNext() {
        while(!sn.empty()) {
            auto& p1=sn.top();
            auto& p2=se.top();
            if(p1==p2){
                sn.pop();
                se.pop();
                continue;
            }
            if(p1->isInteger()){
                return true;
            }
            auto &ls=p1++->getList();
            sn.push(ls.begin());
            se.push(ls.end());
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */