class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] ^ arr[i];
        }

        vector<int> res;
        for(int i = 0; i < queries.size(); i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            if(x == 0) res.push_back(prefix[y]);
            else res.push_back(prefix[y] ^ prefix[x-1]);
        }
        return res;
    }
};