class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        for(auto it : knowledge) {
            mpp[it[0]] = it[1];
        }

        int i = 0;
        int j = s.size() - 1;
        string res = "";
        while(i <= j) {
            if(s[i] == '(') {
                string key = "";
                i++;
                while(s[i] != ')') {
                    key += s[i];
                    i++;
                }
                if(mpp.find(key) == mpp.end()) res += "?";
                else res += mpp[key];
            }
            else if(isalpha(s[i])) {
                res += s[i];
            }
            i++;
        }
        return res;
    }
};