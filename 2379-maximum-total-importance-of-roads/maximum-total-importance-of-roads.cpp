class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> deg(n, 0);
        for(auto it : roads) {
            deg[it[0]]++;
            deg[it[1]]++;
        }
        sort(deg.begin(), deg.end());

        long long val = 1;
        long long res = 0;
        for(auto it : deg) {
            res += val * it;
            val++;
        }
        return res;
    }
};