class Solution {
public:
    int appendCharacters(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i = 0;
        int j = 0;
        int n = s.length();
        int m = t.length();

        while(i < n && j < m) {
            if(t[j] == s[i]) {
                i++;
                j++;
            }
            else i++;
        }
        return m - j;
    }
};