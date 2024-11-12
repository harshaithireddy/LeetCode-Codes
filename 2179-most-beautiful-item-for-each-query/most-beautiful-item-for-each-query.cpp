auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();

        vector<pair<int, int>> V;
        for(int i = 0; i < m; i++) V.push_back({queries[i], i});

        sort(V.begin(), V.end());
        sort(items.begin(), items.end());

        int maxi = 0, i = 0;
        vector<int> res(m);
        for(auto it : V) {
            int price = it.first;
            int ind = it.second;
            while(i < n && items[i][0] <= price) {
                maxi = max(maxi, items[i][1]);
                i++;
            }
            res[ind] = maxi;
        } 
        return res;
    }
};