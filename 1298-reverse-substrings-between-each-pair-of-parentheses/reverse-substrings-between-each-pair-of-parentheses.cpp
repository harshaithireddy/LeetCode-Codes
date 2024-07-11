class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string str = "";

        for(auto it : s) {
            if(it == '(') {
                st.push(str);
                str = "";
            }
            else if(it == ')') {
                reverse(str.begin(), str.end());
                
                if(!st.empty()) {
                    str = st.top() + str;
                    st.pop();
                }
            }
            else str += it;
        }
        return str;
    }
};