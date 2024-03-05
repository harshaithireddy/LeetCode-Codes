class Solution {
public:
    int minimumLength(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(i < j && s[i] == s[j]) {
            while(i < j && s[i + 1] == s[i]) i++;
            while(i < j && s[j] == s[j - 1]) j--;

            i++;
            j--;
        }
        return max(0, j - i + 1);
    }
};