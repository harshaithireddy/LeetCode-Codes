class Solution {
public:
    bool canChange(string start, string target) {
        int s_id = 0, t_id = 0;
        int n = start.size();

        while(s_id < n || t_id < n) {
            while(s_id < n && start[s_id] == '_') s_id++;
            while(t_id < n && target[t_id] == '_') t_id++;

            if(s_id == n && t_id == n) return true;
            if(s_id == n || t_id == n) return false;

            if((start[s_id] != target[t_id]) || (start[s_id] == 'L' && t_id > s_id) || (start[s_id] == 'R' && s_id > t_id)) return false;
            
            s_id++;
            t_id++;
        }
        return true;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();