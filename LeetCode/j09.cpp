class CQueue {
public:
    stack<int> is,os;
    CQueue() {
    }
    
    void appendTail(int value) {
        is.push(value);
    }
    
    int deleteHead() {
        int t;
        if(is.empty()&&os.empty())return -1;
        if(os.empty()){
            while(!is.empty()){
                t=is.top();
                is.pop();
                os.push(t);
            }
        }
        t=os.top();
        os.pop();
        return t;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */