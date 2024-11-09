char init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;
        for(int i = 1; i < n; i++) {
            res = (res + 1) | x;
        }
        return res;
    }
};