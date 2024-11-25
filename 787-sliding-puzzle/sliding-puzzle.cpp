class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> directions = { 
            {1, 3}, {0, 2, 4}, {1, 5}, 
            {0, 4}, {1, 3, 5}, {2, 4} 
        };

        string target = "123450";
        string startState;
        for(auto row : board) {
            for(int num : row) {
                startState += to_string(num);
            }
        }

        unordered_set<string> visited;
        queue<string> q;
        q.push(startState);
        visited.insert(startState);

        int moves = 0;
        while(!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                string curr = q.front();
                q.pop();

                if(curr == target) return moves;

                int zeroPos = curr.find('0');
                for(int newZeroPos : directions[zeroPos]) {
                    string nextState = curr;
                    swap(nextState[zeroPos], nextState[newZeroPos]);

                    if(visited.count(nextState)) continue;

                    visited.insert(nextState);
                    q.push(nextState);
                }
            }
            moves++;
        }
        return -1;
    }
};