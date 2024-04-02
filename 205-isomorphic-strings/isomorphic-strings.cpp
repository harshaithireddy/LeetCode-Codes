class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char, char> mpp;
        unordered_map<char, bool> used;
        for(int i = 0; i < s.size(); i++) {
            if(mpp.find(s[i]) != mpp.end()) {
                if(mpp[s[i]] != t[i]) return false;
            }
            else {
                if(used[t[i]] == true) return false;
                mpp[s[i]] = t[i];
                used[t[i]] = true;
            }
        }
        return true;
    }
};