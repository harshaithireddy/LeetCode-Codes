class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0;
        for(char c = 'a'; c <= 'z'; c++){
            int l = s.find(c);
            if(l == string::npos) continue;

            int r = s.find_last_of(c);
            if(l != r)
                res += unordered_set<char>(s.begin() + l + 1, s.begin() + r).size();
        }
        return res;
    }
};