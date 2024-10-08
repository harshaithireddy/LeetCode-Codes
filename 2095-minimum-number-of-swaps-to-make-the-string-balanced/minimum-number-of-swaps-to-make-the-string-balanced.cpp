class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int open = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '[') cnt++;
            else if(cnt > 0) cnt--;
        }
        return (cnt + 1) / 2;
    }
};