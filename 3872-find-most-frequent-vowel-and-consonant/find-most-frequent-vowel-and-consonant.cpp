class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26], maxV = 0, maxC = 0;
        for(char ch : s) {
            int i = ch - 'a';
            freq[i]++;
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                maxV = max(maxV, freq[i]);
            }
            else {
                maxC = max(maxC, freq[i]);
            }
        }
        return maxV + maxC;
    }
};