class Solution {
public:
    vector<string> res;
    void solve(int i, string &sentence, string &s, unordered_map<string, bool> &doesExist) {
        if(i >= s.size()) {
            res.push_back(sentence);
            return;
        }

        for (int j = i + 1; j <= i + 10  &&  j <= s.size(); j++) {
            string word = s.substr(i, j - i);
            if(doesExist.find(word) != doesExist.end()) {
                if(sentence.size() == 0) {
                    sentence = word;
                } else {
                    sentence += " " + word;
                }
                solve(j, sentence, s, doesExist);
                int x = 0;
                while(x < word.size()) {
                    x++;
                    sentence.pop_back();
                }

                if(sentence.size() > 0) {
                    sentence.pop_back();
                }
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        string sentence = "";
        unordered_map<string, bool> doesExist;
        for(auto it : wordDict) {
            doesExist[it] = true;
        }

        res.clear();
        solve(0, sentence, s, doesExist);
        return res;
    }
};
