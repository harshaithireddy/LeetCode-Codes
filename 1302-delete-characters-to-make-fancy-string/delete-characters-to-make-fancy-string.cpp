class Solution {
public:
    string makeFancyString(string s) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        string res;
        int cnt = 1;
        res += s[0];

        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1]) {
                cnt++;
                if(cnt < 3) {
                    res += s[i];
                }
            }
            else {
                cnt = 1;
                res += s[i];
            }
        }
        return res;
    }
};
