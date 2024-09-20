class Solution {
public:
    string shortestPalindrome(string s) {
        string str(s.rbegin(), s.rend());

        for(int i = 0; i < s.size(); i++) {
            if(s.compare(0, s.size() - i, str, i, s.size() - i) == 0) return str.substr(0, i) + s;  
        }
        return "";
    }
};