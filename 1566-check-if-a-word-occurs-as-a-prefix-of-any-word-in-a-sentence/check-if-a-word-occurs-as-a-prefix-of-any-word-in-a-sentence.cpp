class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int res = 1;
        int n = sentence.size();
        int m = searchWord.size();
        
        int j = 0;
        while(j < n) {
            int i = 0;
            while(j < n && sentence[j] != ' ' && i < m && sentence[j] == searchWord[i]) {
                i++;
                j++;
            }
            
            if(i == m) return res;
            
            while(j < n && sentence[j] != ' ') j++;
            if(j < n) res++;

            j++;
        }
        return -1;
    }
};
