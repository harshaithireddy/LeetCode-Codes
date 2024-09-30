class CustomStack {
public:
    int speedup = []{ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
    
    vector<int> V;
    int n;

    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if(V.size() == n) return;
        V.push_back(x);
    }
    
    int pop() {
        if(V.empty()) return -1;
        int ele = V.back();
        V.pop_back();
        return ele;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < k && i < V.size(); i++) {
            V[i] += val;
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