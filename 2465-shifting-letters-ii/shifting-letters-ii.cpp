class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1,0);

        for(auto shift : shifts){
            if(shift[2] == 1) {
                diff[shift[0]]++;
                diff[shift[1] + 1]--;
            }
            else {
                diff[shift[0]]--;
                diff[shift[1] + 1]++;
            }
        }

        for(int i = 1; i <= n; i++){
            diff[i] += diff[i-1]; 
        }

        string res;
        for(int i = 0; i < n; i++) {
            int cnt = diff[i] % 26;
            if(cnt < 0) cnt = cnt + 26;
            char curr = char('a' + (s[i] - 'a' + cnt) % 26);
            res.push_back(curr);
        }
        return res;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();