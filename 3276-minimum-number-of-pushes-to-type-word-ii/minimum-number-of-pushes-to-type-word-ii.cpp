class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for(int i = 0; i < word.size(); i++) {
            freq[word[i] - 'a']++; 
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int res = 0, d = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                res += freq[i] * (1 + int(d / 8));
                d += 1;
            }
        }
        return res;
    }
};