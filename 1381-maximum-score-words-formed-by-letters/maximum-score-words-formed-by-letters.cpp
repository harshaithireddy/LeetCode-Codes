class Solution {
public:
    int dfs(vector<string>& words, vector<int>& score, vector<int>& freq, int i) {
        int n = words.size();
        if(i == n) return 0;

        int skip = dfs(words, score, freq, i+1), scor = 0;

        bool valid = true;

        for(auto it : words[i]) {
            if(--freq[it - 'a'] < 0) valid = false;
            scor += score[it - 'a'];
        }
        int pick = valid ? scor + dfs(words, score, freq, i + 1) : 0;

        for(auto it : words[i]) freq[it - 'a']++;
        return max(skip, pick);
        
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = letters.size();
        vector<int> freq(26, 0);
        for(auto it : letters) freq[it - 'a']++;

        return dfs(words, score, freq, 0);
    }
};