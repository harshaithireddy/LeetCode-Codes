class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mpp;
        for(int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
        }

        int res = 0;
        for(auto it : mpp) {
            int cnt = it.second;
            while(cnt >= 3) {
                cnt -= 2;
            }
            res += cnt;
        }
        return res;
    }
};