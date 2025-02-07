class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> col;
        unordered_map<int, int> rev;

        int n = queries.size();
        vector<int> res(n);
        
        for(int i = 0; i < n; i++) {
            int x = queries[i][0];
            int y = queries[i][1];

            int z = col[x];
            if(rev.find(z) != rev.end()) {
                rev[z]--;
                if(rev[z] == 0) rev.erase(z);
            }
            rev[y]++;
            col[x] = y;
            res[i] = rev.size();
        }
        return res;
    }
};