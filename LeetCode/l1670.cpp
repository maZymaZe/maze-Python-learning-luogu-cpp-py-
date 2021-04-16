class FrontMiddleBackQueue {
public:
    deque<int> a,b;
    FrontMiddleBackQueue() {

    }
    
    void pushFront(int val) {
        a.push_front(val);
        if(a.size()-b.size()>1){
            int t=a.back();
            a.pop_back();
            b.push_front(t);
        }
    }
    
    void pushMiddle(int val) {
        if(a.size()==b.size()){
            a.push_back(val);
        }else{
            int t=a.back();
            a.back()=val;
            b.push_front(t);
        }
    }
    
    void pushBack(int val) {
        if(a.empty()){
            a.push_back(val);
            return;
        }
        if(a.size()==b.size()){
            int t=b.front();
            a.push_back(t);
            b.pop_front();
        }
        b.push_back(val);
    }
    
    int popFront() {
        if(a.empty())return -1;
        int ret=a.front();
        if(a.size()==b.size()){
            a.pop_front();
            int t=b.front();
            b.pop_front();
            a.push_back(t);
        }else{
            a.pop_front();
        }
        return ret;
    }
    
    int popMiddle() {
        if(a.empty())return -1;
        int ret=a.back();
        if(a.size()==b.size()){
            int t=b.front();
            a.back()=t;
            b.pop_front();
        }else{
            a.pop_back();
        }
        return ret;
    }
    
    int popBack() {
        if(a.empty())return -1;
        if(b.empty()){
            int t=a.back();
            a.pop_back();
            return t;
        }
        int ret=b.back();
        if(a.size()==b.size()){
            b.pop_back();
        }else{
            int t=a.back();
            b.push_front(t);
            a.pop_back();
            b.pop_back();
        }
        return ret;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */