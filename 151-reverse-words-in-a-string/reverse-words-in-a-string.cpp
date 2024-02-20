class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j && s[i] == ' ') {
            i++;
        }
        while (i < j && s[j] == ' ') {
            j--;
        }

        vector<string> V;
        string str = "";
        for(int k = i; k <= j; k++) {
            if(s[k] != ' ') {
                str += s[k];
            }
            else {
                if(!str.empty()) {
                    V.push_back(str);
                    str = "";
                }
            }
        }
        if(!str.empty()) {
            V.push_back(str);
        }

        string res = "";
        for(int i = V.size() - 1; i >= 0; i--) {
            res += V[i];
            if(i != 0) {
                res += " ";
            }
        }
        return res;
    }
};
