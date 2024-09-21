class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> V;
        for(int i = 1; i <= n; i++) {
            V.push_back(i);
        }

        sort(V.begin(), V.end(), [](int a, int b) {
            return to_string(a) <= to_string(b);
        });

        return V;
    }
};