class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> s1(26, 0), t1(26, 0);
        for(auto i : s) s1[i - 'a']++;
        for(auto i : t) t1[i - 'a']++;

        int res = 0;
        for(int i = 0; i < 26; i++) {
            res += abs(s1[i] - t1[i]);
        }
        return res;
    }
};