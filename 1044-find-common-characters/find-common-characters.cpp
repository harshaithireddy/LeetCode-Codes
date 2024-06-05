class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq(26, 100);

        for(auto it : words) {
            vector<int> V(26 , 0);
            for(auto ch : it) {
                V[ch - 'a']++;
            }

            for(int i = 0; i < 26; i++) {
                freq[i] = min(freq[i], V[i]);
            }
        }

        vector<string> res;
        for(int i = 0; i < 26; i++) {
            while(freq[i]--) {
                res.push_back(string(1, i + 'a'));
            }
        }
        return res;
    }
};