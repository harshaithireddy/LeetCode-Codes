auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '[') cnt++;
            else if(cnt > 0) cnt--;
        }
        return (cnt + 1) / 2;
    }
};