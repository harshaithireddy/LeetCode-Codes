class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1) return 1;
        unordered_map<int, vector<int>> mpp;
        for(auto it : trust) {
            mpp[it[1]].push_back(it[0]);
        }
        
        unordered_map<int, int> mpp2;
        for(auto it : trust) {
            mpp2[it[0]]++;
        }

        // if(mpp.size() > 1) return -1;
        for(auto it : mpp) {
            vector<int> x = it.second;
            cout << it.first << "->";
            for(auto i : x) cout << i << " ";
        }
        for(auto it : mpp) {
            if(it.second.size() == n-1 && mpp2.find(it.first) == mpp2.end()) return it.first; 
        }
        return -1;
    }
};