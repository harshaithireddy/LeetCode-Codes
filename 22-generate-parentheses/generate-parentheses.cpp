class Solution {
private:
    void Generate(vector<string>& ans, int close, int open, string s) {
        if(open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }
        if(open != 0) Generate(ans, close, open-1, s+'(');
        if(close > open) Generate(ans, close-1, open, s+')');
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        Generate(ans, n, n, "");
        return ans;
    }
};