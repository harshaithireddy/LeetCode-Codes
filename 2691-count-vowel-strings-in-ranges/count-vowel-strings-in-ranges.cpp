class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 1, 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'}; 

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];
            if(vowels.count(words[i].front()) && vowels.count(words[i].back())) {
                prefix[i + 1]++;  
            }
        }
        vector<int> res; 
        for(auto it : queries) {
            int L = it[0], R = it[1];  
            res.push_back(prefix[R + 1] - prefix[L]);  
        }
        return res;  
    }
};