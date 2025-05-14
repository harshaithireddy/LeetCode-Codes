class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> freq1(26, 0), freq2(26, 0);
        int i = 0, j = 0;
        int n = p.size();

        for(auto it : p) freq1[it - 'a']++;
        
        while(j < s.size()) {
            freq2[s[j] - 'a']++;
            if(j - i + 1 < n) j++;
            else if(j - i + 1 == n) {
                if(freq1 == freq2) res.push_back(i);
                freq2[s[i] - 'a']--;
                i++;
                j++;
            } 
        }
        return res;
    }
};