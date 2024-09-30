class CustomStack {
public:
    deque<int> dq;
    int n;

    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if(dq.size() == n) return;
        dq.push_front(x);
    }
    
    int pop() {
        if(dq.empty()) return -1;
        int ele = dq.front();
        dq.pop_front();
        return ele;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < k && i < dq.size(); i++) {
            dq[dq.size() - i - 1] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */