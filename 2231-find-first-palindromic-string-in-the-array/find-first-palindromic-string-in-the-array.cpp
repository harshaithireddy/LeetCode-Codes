class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto word : words) {
            if(isPalindrome(word) == true) return word;
        }
        return "";
    }
};