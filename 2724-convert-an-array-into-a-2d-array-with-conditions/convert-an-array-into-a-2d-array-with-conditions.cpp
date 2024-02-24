class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> V;
        
        map<int, int> mpp;
        for(auto it : nums) {
            mpp[it]++;
        }
        
        while(!mpp.empty()) {
            vector<int> x;
            for(auto it = mpp.begin(); it != mpp.end();) {
                if(it->second > 0) {
                    x.push_back(it->first);
                    it->second--;

                    if(it->second == 0) it = mpp.erase(it);
                    else it++;
                }
                else {
                    it++;
                }
            }
            V.push_back(x);
        }
        return V;
    }
};
