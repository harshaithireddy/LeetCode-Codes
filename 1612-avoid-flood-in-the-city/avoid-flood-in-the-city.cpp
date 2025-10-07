class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> mpp;
        set<int> st;
        vector<int> ans(n, 1);

        for(int i = 0; i < n; i++) {
            if(rains[i] == 0) st.insert(i);
            else {
                if(mpp.find(rains[i]) != mpp.end()) {
                    auto x = st.upper_bound(mpp[rains[i]]);
                    if(x != st.end()) {
                        ans[*x] = rains[i];
                        st.erase(x);
                    }
                    else return {};
                }
                ans[i] = -1;
                mpp[rains[i]] = i;
            }
        }
        return ans;
    }
};