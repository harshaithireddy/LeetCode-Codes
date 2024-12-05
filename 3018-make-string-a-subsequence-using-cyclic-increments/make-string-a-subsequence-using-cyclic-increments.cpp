class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int j = 0;
        int n = str1.size();
        int m = str2.size();

        for(int i = 0; i < n; i++) {
            if(str1[i] == str2[j] || ((str1[i] - 'a' + 1) % 26 == (str2[j] - 'a'))) {
                j++;
            }
            if(j == m) return true;
        }
        return false;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();