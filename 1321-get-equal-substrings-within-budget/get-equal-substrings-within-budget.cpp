class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0;
        int j = 0;
        int res = 0;
        int currCost = 0;

        while(j < s.size()) {
            currCost += abs(s[j] - t[j]);
            while(i <= j && currCost > maxCost) {
                currCost -= abs(s[i] - t[i]);
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};
