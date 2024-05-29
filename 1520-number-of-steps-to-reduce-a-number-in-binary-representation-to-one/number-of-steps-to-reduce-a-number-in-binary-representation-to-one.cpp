class Solution {
public:
    int numSteps(string s) {
        int res = 0;
        int carry = 0;
        for(int i = s.size()-1; i >= 1; i--) {
            if((s[i] - '0' + carry) % 2 == 1) {
                res += 2;
                carry = 1;
            }
            else {
                res += 1;
            }
        }
        return res + carry;
    }
};