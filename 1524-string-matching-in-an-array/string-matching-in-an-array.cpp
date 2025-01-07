class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> res;
        for(int i = 0; i < n; i++) {
            bool flag = false;
            for(int j = 0; j < n; j++) {
                if(i != j && words[i] != words[j] && words[j].find(words[i]) != string::npos) {
                    flag = true;
                }
            }
            if(flag) res.push_back(words[i]);
        }
        return res;
    }
};