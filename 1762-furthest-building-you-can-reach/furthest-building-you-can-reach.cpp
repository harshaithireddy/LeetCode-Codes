class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;

        for(int i = 1; i < heights.size(); i++) {
            if(heights[i] <= heights[i-1]) continue;

            bricks -= (heights[i] - heights[i-1]);
            pq.push(heights[i] - heights[i-1]);

            if(bricks < 0) {
                bricks += pq.top();
                pq.pop();
                ladders--;
            }

            if(ladders < 0) {
                return i - 1;
            }
        }
        return heights.size() - 1;
    }
};