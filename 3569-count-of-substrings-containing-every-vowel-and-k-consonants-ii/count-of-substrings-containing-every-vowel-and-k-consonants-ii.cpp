class Solution {
public:
    long long cnt(string word, int k) {
        long long res = 0;
        int l = 0;
        unordered_map<char, int> vow;
        int con = 0;
        int n = word.size();

        for(int r = 0; r < n; r++) {
            char ch = word[r];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vow[ch]++;
            }
            else con++;

            while(vow.size() == 5 && con >= k) {
                res += n - r;
                char ch = word[l];
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    vow[ch]--;
                    if(vow[ch] == 0) vow.erase(ch); 
                }
                else con--;

                l++;
            }
        }
        return res;
    }
    long long countOfSubstrings(string word, int k) {
        return cnt(word, k) - cnt(word, k + 1);
    }
};