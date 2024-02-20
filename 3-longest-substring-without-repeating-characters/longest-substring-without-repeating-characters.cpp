class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        for(int i = 0; i < s.size(); i++) {
            unordered_map<char, int> mpp;
            for(int j = i; j < s.size(); j++) {
                mpp[s[j]]++;
                if(mpp[s[j]] > 1) {
                    int size = mpp.size();
                    maxi = max(maxi, size);
                    break;
                }
            }
            int size = mpp.size();
            maxi = max(maxi, size);
            if(maxi == s.size()) break;
        }
        return maxi;
    }
};