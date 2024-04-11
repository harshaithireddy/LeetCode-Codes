class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(auto ch : num) {
            while(!st.empty() && st.top() > ch && k > 0) {
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        int lastIndex;
        for(int i = res.size() - 1; i >= 0; i--) {
            if(res[i] != '0') {
                lastIndex = i;
                break;
            }
        }
        res = res.substr(0, lastIndex + 1);
        reverse(res.begin(), res.end());

        if(res == "") return "0";
        return res;
    }
};