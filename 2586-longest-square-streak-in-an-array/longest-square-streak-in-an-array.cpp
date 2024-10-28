class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> V(st.begin(), st.end());

        sort(V.begin(), V.end());

        int maxi = -1;
        for(auto it : V) {
            long long curr = it;
            int cnt = 0;
            while(st.find(curr) != st.end()) {
                st.erase(curr);
                curr *= curr;
                cnt++;
            }
            maxi = max(maxi, cnt);
        }
        if(maxi > 1) return maxi;
        return -1;
    }
};