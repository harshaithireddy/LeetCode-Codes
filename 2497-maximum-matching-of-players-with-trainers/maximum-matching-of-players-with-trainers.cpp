class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0;
        int j = 0;
        int cnt = 0;
        while(i < players.size() && j < trainers.size()) {
            while(j < trainers.size() && trainers[j] < players[i]) j++;
            if(j < trainers.size()) {
                cnt++;
                i++;
                j++;
            }
            else i++;
        }
        return cnt;
    }
};