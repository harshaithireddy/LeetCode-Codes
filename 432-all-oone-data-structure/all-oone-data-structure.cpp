class AllOne {
public:
    unordered_map<string, int> mpp;
    set<pair<int, string>> st;
    AllOne() {
        
    }
    
    void inc(string key) {
        st.erase({mpp[key], key});
        mpp[key]++;
        
        st.insert({mpp[key], key});
    }
    
    void dec(string key) {
        st.erase({mpp[key], key});
        mpp[key]--;
        
        if(mpp[key] > 0) st.insert({mpp[key], key});
    }
    
    string getMaxKey() {
        if(st.size() == 0) return "";
        return st.rbegin()->second;
    }
    
    string getMinKey() {
        if(st.size() == 0) return "";
        return st.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */