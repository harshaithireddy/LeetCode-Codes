class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if(hand.size() % groupSize != 0) return false;

        map<int, int> mpp;
        for(auto it : hand) mpp[it]++;

        for(auto it : mpp) {
            if(it.second == 0) continue;
            while(it.second--) {
                for(int i = it.first; i < it.first + groupSize; i++) {
                    if(mpp[i] == 0) return false;
                    mpp[i]--;
                }
            }
        }
        return true;
    }
};