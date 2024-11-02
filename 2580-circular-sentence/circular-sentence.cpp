class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        char last = sentence[0];
        bool flag = true;
        for(int i = 1; i < n; i++) {
            if(sentence[i] == ' ') {
                if(sentence[i + 1] != last) {
                    flag = false;
                    break;
                }
            }
            last = sentence[i];
        }
        if(last != sentence[0]) flag = false;

        return flag;
    }
};