class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char, int> mpp;
        int cnt = 0;
        for(int i = 0; i < 3; i++) {
            mpp[s[i]]++;
        }
        if(mpp.size() == 3) cnt++;

        for(int i = 3; i < s.size(); i++) {
            mpp[s[i-3]]--;
            if(mpp[s[i-3]] == 0) mpp.erase(s[i - 3]);
            mpp[s[i]]++;

            if(mpp.size() == 3) cnt++;
        }
        return cnt;
    }
};