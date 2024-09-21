class Solution {
public:
    int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();

    vector<int> lexicalOrder(int n) {
        vector<string> V;
        for(int i = 1; i <= n; i++) {
            V.push_back(to_string(i));
        }
        sort(V.begin(), V.end());

        vector<int> res;
        for(int i = 0; i < V.size(); i++) res.push_back(stoi(V[i]));

        return res;
    }
};