class MyCalendar {
    map<int, int> mpp;
public:
    int speedup = []{ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
    
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto next = mpp.lower_bound(start);
        if(next != mpp.end() && next->first < end) {
            return false;
        }
        if(next != mpp.begin() && prev(next)->second > start) {
            return false;
        }
        mpp[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */