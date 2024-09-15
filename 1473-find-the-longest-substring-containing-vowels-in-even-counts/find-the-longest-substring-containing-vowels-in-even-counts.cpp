class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int cnt = 0;
        int res = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                cnt ^= (1 << ((int)(s[i] - 'a')));
            }
            if(mp.count(cnt)) {
                res = max(res, i - mp[cnt]);
            }
            else {
                mp[cnt] = i;
            }
        }
        return res;
    }
};