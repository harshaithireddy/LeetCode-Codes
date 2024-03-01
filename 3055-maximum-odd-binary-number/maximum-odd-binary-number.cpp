class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(), s.end());
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                swap(s[i], s[0]);
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};