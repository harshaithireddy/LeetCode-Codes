class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> count(26, 0);
        vector<string> res;

        for(string s : words2) {
            vector<int> c1(26,0);
            for(char ch : s) c1[ch - 'a']++;

            for(int i = 0; i < 26; i++) {
                count[i] = max(count[i],c1[i]);
            }
        }

        for(string s : words1) {
            vector<int> c1(26,0);
            int flag = 1;

            for(char ch : s) {
                c1[ch - 'a']++;
            }
            for(int i = 0; i < 26; i++) {
                if(count[i] > c1[i]) flag = 0;
            }
            if(flag) res.push_back(s);
        }
        return res;
    }
};