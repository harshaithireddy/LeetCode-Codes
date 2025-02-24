class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int l = 0, r = 0;
        int maxi = 0;

        while(r < s.size()) {
            mpp[s[r]]++;
            if(mpp[s[r]] > 1) {
                while(mpp[s[r]] > 1) {
                    mpp[s[l]]--;
                    l++;
                }
            }
            maxi = max(maxi, (r - l + 1));
            r++;
        }
        return maxi;
    }
};