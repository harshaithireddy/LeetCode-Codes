class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mpp;
        for(int i = 0; i < s1.size(); i++) {
            string word = "";
            while(i < s1.size() && s1[i] != ' ') {
                word += s1[i];
                i++;
            }
            if(!word.empty()) mpp[word]++;
        }

        for(int i = 0; i < s2.size(); i++) {
            string word = "";
            while(i < s2.size() && s2[i] != ' ') {
                word += s2[i];
                i++;
            }
            if(!word.empty()) mpp[word]++;
        }

        vector<string> res;
        for(auto it : mpp) {
            if(it.second == 1) res.push_back(it.first);
        }
        return res;
    }
};