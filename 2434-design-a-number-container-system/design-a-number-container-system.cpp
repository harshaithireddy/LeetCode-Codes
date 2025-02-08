class NumberContainers {
public:
    unordered_map<int, int> mpp1;
    unordered_map<int, set<int>> mpp2;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mpp1.find(index) != mpp1.end()) {
            mpp2[mpp1[index]].erase(index);
        }
        
        mpp1[index] = number;
        mpp2[number].insert(index);
    }
    
    int find(int number) {
        if(mpp2[number].empty()) return -1;
        return *mpp2[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */