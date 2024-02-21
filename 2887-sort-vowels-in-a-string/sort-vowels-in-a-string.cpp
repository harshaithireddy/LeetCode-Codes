class Solution {
private:
    bool isVowel(char ch) {
        ch = (char)tolower(ch);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
public:
    string sortVowels(string s) {
        vector<char> V;
        for(int i = 0; i < s.size(); i++) {
            if(isVowel(s[i])) V.push_back(s[i]);
        }

        sort(V.begin(), V.end());
        
        int k = 0;
        for(int i = 0; i < s.size(); i++) {
            if(isVowel(s[i])) {
                s[i] = V[k];
                k++;
            }
        }
        return s;
    }
};