class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.empty()) return 0;
        int i = 0;
        string res = "";
        while(i < s.size()) {
            if(!res.empty() && res.back() == '(' && s[i] == ')') res.pop_back();
            else res.push_back(s[i]);
            i++;
        }
        return res.size();
    }
};