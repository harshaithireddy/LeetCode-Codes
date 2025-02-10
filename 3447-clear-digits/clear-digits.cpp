class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i]) && !st.empty()) st.pop();
            else st.push(s[i]);
        }

        string res;
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};