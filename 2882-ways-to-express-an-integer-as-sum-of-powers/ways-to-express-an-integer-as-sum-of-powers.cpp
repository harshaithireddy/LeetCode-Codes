class Solution {
public:
    const int MOD = 1e9 + 7;
    int dfs(int idx, int total, const vector<int>& powers, vector<vector<int>>& dp) {
        if(total == 0) return 1;

        if(total < 0 || idx >= powers.size()) return 0;
        if(dp[idx][total] != -1) return dp[idx][total];
        
        int pick = dfs(idx + 1, total - powers[idx], powers, dp);
        int notPick = dfs(idx + 1, total, powers, dp);
        
        return dp[idx][total] = (pick + notPick) % MOD;
    }

    int numberOfWays(int n, int x) {
        vector<int> powers;
        for(int i = 1; pow(i, x) <= n; i++) {
            powers.push_back((int)pow(i, x));
        }
        
        vector<vector<int>> dp(powers.size(), vector<int>(n + 1, -1));
        return dfs(0, n, powers, dp);
    }
};