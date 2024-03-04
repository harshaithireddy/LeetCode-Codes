class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.empty()) return 0;

        sort(tokens.begin(), tokens.end());
        if(tokens[0] > power) return 0;

        int i = 0;
        int j = tokens.size() - 1;
        
        int score = 0;
        int maxi = -1;
        while(i <= j) {
            if(tokens[i] <= power) {
                score += 1;
                power -= tokens[i];
                i++;
            }
            else if(score > 0 && power + tokens[j] > tokens[i]) {
                score -= 1;
                power += tokens[j];
                j--;
            }
            else {
                i++;
                j--;
            }
            maxi = max(maxi, score);
        }
        return maxi;
    }
};