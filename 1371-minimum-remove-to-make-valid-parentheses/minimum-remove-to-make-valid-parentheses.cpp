class Solution {
public:
    string minRemoveToMakeValid(string s) {
        ios_base::sync_with_stdio(false);
        int open = 0;
        unordered_set<int> set;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') open++;
            else if(s[i] == ')') {
                if(open > 0) open--;
                else set.insert(i);
            }
        }
        for(int i = s.size()-1; i >= 0 && open > 0; i--) {
            if(s[i] == '(') {
                open--;
                set.insert(i);
            }
        }

        string res = "";
        for(int i = 0; i < s.size(); i++) {
            if(!set.contains(i)) res.push_back(s[i]); 
        }
        return res;
    }
};