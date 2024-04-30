class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> mpp;
        for(int i = 0; i < s.size(); i++) mpp[s[i]] = i;
        int res = -1;
        for(int i = 0; i < s.size(); i++) res = max(res, mpp[s[i]] - i - 1);
        return res;
    }
};