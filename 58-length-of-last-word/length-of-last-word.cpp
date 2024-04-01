class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size() - 1;
        while(n) {
            if(s[n] == ' ') {
                n--;
                continue;
            }
            else break;
        }
        int cnt = 0;
        for(int i = n; i >= 0; i--) {
            if(s[i] == ' ') break;
            cnt++;
        }
        return cnt;
    }
};