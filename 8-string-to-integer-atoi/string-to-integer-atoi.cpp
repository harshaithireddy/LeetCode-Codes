class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        int n = s.size();
        int i = 0;
        
        while(i < n && s[i] == ' ') {
            i++;
        }
        
        int sign = 1;
        if(i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        while(i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            res = res * 10 + digit;
            i++;
            
            if(res * sign > INT_MAX) return INT_MAX;
            if(res * sign < INT_MIN) return INT_MIN;
        }
        
        return int(res * sign);
    }
};
