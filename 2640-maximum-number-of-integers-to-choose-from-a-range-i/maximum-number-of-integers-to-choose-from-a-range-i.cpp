class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(banned.begin(), banned.end());

        int cnt = 0;
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            if(sum + i > maxSum) break;
            if(st.find(i) == st.end()) {
                cnt++;
                sum += i;
            }
        }
        return cnt;
    }
};