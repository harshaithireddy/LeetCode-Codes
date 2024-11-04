class Solution {
public:
    string compressedString(string word) {
        string res = "";
        char curr = word[0];
        int cnt = 1;

        for(int i = 1; i < word.size(); i++) {
            if(word[i] == curr) {
                cnt++;
            }
            else {
                if(cnt > 0) {
                    res += to_string(cnt);
                    res += curr;
                }
                curr = word[i];
                cnt = 1;
            }

            if(cnt == 9) {
                res += to_string(cnt);
                res += curr;
                cnt = 0;
            }
        }

        if(cnt > 0) {
            res += to_string(cnt);
            res += curr;
        }

        return res;
    }
};
