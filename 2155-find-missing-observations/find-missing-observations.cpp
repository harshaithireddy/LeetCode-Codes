class Solution {
public:
    int speedup = []{ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int rollsSum = 0;
        for(int i = 0; i < m; i++) rollsSum += rolls[i];

        int nTotal = (mean * (m + n)) - rollsSum;
        if(nTotal < n || nTotal > n * 6) return {};

        vector<int> res;
        while(nTotal) {
            int dice = min(nTotal - n + 1, 6);
            res.push_back(dice);
            nTotal -= dice;
            n -= 1;
        }
        return res;
    }
};