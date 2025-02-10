class Solution {
public:
    string clearDigits(string s) {
        string res = "";
        for(int i = 0; i < s.size(); i++) {
            if(!isdigit(s[i])) {
                res += s[i];
            }
            else {
                if(res != "") res.pop_back();
            }
        }
        return res;
    }
};