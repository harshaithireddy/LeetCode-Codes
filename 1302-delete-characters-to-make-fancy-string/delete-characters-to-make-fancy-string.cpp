class Solution {
public:
    string makeFancyString(string s) {
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
