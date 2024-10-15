class Solution {
public:
    long long minimumSteps(string s) {
        long long cnt = 0, res = 0;
        for(int i = s.size() - 1; i >=0 ; i--) {
            if(s[i] == '0') cnt++;
            else res += cnt;
        }
        return res;
    }
};