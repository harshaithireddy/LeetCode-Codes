class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> st_lock;
        stack<int> st_unlock;

        for(int i = 0; i < s.size(); i++) {
            if(locked[i] == '0') st_unlock.push(i);
            else if(s[i] == '(') st_lock.push(i);
            else {
                if(!st_lock.empty()) st_lock.pop();
                else if(!st_unlock.empty()) st_unlock.pop();
                else return false;
            }
        }

        while(!st_lock.empty() && !st_unlock.empty() && st_lock.top() < st_unlock.top()) {
            st_lock.pop();
            st_unlock.pop();
        }

        if(!st_lock.empty()) return false;

        if(st_unlock.size() % 2 == 0) return true;
        return false;
    }
};