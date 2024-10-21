class Solution {
public:
    void fun(string& s, int ind, int& maxCount, unordered_set<string>& st) {
        if(ind == s.size()) {
            if(st.size() > maxCount) maxCount = st.size();
            return;
        }
        string substr;
        for(int i = ind; i < s.size(); i++) {
            substr.push_back(s[i]);

            if(st.count(substr) == 0) {
                st.insert(substr);
                fun(s, i + 1, maxCount, st);
                st.erase(substr);
            }
        }
    }

    int maxUniqueSplit(string s) {
        int maxCount = 0;
        unordered_set<string> st;
        fun(s, 0, maxCount, st);

        return maxCount;
    }
};