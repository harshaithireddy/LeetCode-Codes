class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }

    void dfs(int i, string& s, vector<string>& path, vector<vector<string>>& res) {
        if(i == s.length()) {
            res.push_back(path);
            return;
        }
        for(int end = i; end < s.length(); end++) {
            if(isPalindrome(s, i, end)) {
                path.push_back(s.substr(i, end - i + 1));
                dfs(end + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<string>> res;
        if(s.empty()) return res;

        vector<string> path;
        dfs(0, s, path, res);

        return res;
    }
};