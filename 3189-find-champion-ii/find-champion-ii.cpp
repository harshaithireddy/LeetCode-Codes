class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> V(n, 0);

        for(auto it : edges) {
            V[it[1]]++;
        }

        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(V[i] == 0) {
                cout << i << " ";
                res.push_back(i);
            }
        }

        if(res.size() > 1) return -1;
        return res[0];
    }
};