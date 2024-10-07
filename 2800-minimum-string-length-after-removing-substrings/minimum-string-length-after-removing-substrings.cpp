class Solution {
public:
    int minLength(string s) {
        string res = "";
        for(int i = 0; i < s.size(); i++) {
            if(res != "" && res.back() == 'A' && s[i] == 'B') res.pop_back();
            else if(res != "" && res.back() == 'C' && s[i] == 'D') res.pop_back();
            else res.push_back(s[i]);
        }
        return res.size();
    }
};