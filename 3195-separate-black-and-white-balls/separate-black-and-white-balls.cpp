auto speedUp = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c++';
}();

class Solution {
public:
    long long minimumSteps(string s) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        long long cnt = 0, res = 0;
        for(int i = s.size() - 1; i >=0 ; i--) {
            if(s[i] == '0') cnt++;
            else res += cnt;
        }
        return res;
    }
};