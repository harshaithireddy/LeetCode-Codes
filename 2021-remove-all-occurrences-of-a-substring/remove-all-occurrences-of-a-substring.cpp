class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n1 = s.size();
        int n2 = part.size();

        string res = "";

        for(int i = 0; i < n1; i++) {
            res.push_back(s[i]);
            if(res.size() >= n2 && s[i] == part[n2-1]) {
                if(res.substr(res.size() - n2) == part) {
                    res.erase(res.size() - n2);
                }
            }
        }
        return res;
    }
};