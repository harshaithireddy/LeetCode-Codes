class Solution {
public:
    set<string> st;
    string mini;
    string op1(string s, int a) {
        for(int i = 0; i < s.size(); i++) {
            if(i % 2) {
                s[i] = ((s[i] - '0' + a) % 10) + '0';
            }
        }
        return s;
    }

    string op2(string s, int b){
        string temp = s.substr(0, b);
        s.erase(0, b);
        s = s + temp;
        return s;
    }

    void solve(string str, int a, int b){
        if(st.find(str) != st.end()) return;
        mini = min(mini, str);
        st.insert(str);
        string s1 = op1(str, a);
        string s2 = op2(str, b);

        solve(s1, a, b);
        solve(s2,a,b);
    }

    string findLexSmallestString(string s, int a, int b) {
        mini = s;
        solve(s, a, b);
        return mini;
    }
};