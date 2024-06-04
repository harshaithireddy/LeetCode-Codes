class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mpp;
        for(auto it : s) {
            mpp[it]++;
        }

        bool isOdd = false;
        int res = 0;
        for(auto it : mpp) {
            if(it.second % 2 == 0) res += it.second;
            else {
                res += it.second - 1;
                isOdd = true;
            }
        }

        if(isOdd == true) return res + 1;
        return res;
    }
};