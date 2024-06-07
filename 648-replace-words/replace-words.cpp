class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        string res = "";
        int i = 0;
        int n = sentence.size();

        while(i < n) {
            string word = "";
            bool skip = false;
            while(i < n && sentence[i] != ' ') {
                if(skip == true) {
                    i++;
                    continue;
                } 
                word += sentence[i++];
                if(st.find(word) != st.end()) {
                    skip = true;
                }
            }
            res += word;
            if(i < n && sentence[i] == ' ') {
                res += " ";
            }
            i++;
        }
        return res;
    }
};