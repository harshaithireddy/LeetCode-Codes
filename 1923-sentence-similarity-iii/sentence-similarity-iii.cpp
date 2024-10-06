class Solution {
public:
    vector<string> split(const string& x) {
        vector<string> res;
        int i = 0;
        int n = x.size();
        string word = "";

        while(i < n) {
            while(i < n && x[i] == ' ') i++;
            while(i < n && x[i] != ' ') {
                word += x[i];
                i++;
            }
            if(!word.empty()) {
                res.push_back(word);
                word = "";
            }
        }
        return res;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);

        int n = words1.size();
        int m = words2.size();

        int i = 0;
        while(i < n && i < m && words1[i] == words2[i]) {
            i++;
        }

        int j = 0;
        while(j < n-i && j < m-i && words1[n-j-1] == words2[m-j-1]) {
            j++;
        }

        return i + j >= min(n, m);
    }
};