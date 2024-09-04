class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<string, pair<string, string>> mpp;
        mpp["py"] = {"px", "nx"};
        mpp["px"] = {"ny", "py"};
        mpp["ny"] = {"nx", "px"};
        mpp["nx"] = {"py", "ny"};
        
        unordered_set<string> st;
        for(auto obs : obstacles) {
            st.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }

        int x = 0, y = 0;
        string dir = "py";
        int maxDist = 0;

        for(int i = 0; i < commands.size(); i++) {
            int command = commands[i];
            if(command == -1) dir = mpp[dir].first;
            else if(command == -2) dir = mpp[dir].second;
            else {
                for(int step = 0; step < command; step++) {
                    int newX = x, newY = y;
                    if(dir == "py") newY++;
                    else if(dir == "ny") newY--;
                    else if(dir == "px") newX++;
                    else if(dir == "nx") newX--;
                    
                    if(st.find(to_string(newX) + "," + to_string(newY)) == st.end()) {
                        x = newX;
                        y = newY;
                        maxDist = max(maxDist, x * x + y * y);
                    }
                    else break;
                }
            }
        }
        return maxDist;
    }
};