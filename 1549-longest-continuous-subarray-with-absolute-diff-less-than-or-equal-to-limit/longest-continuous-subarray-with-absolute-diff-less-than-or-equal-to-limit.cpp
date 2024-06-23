class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int, int>> maxi;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mini;

        int i = 0;
        int res = INT_MIN;
        for(int j = 0; j < nums.size(); j++) {
            maxi.push({nums[j], j});
            mini.push({nums[j], j});

            while(!maxi.empty() && maxi.top().second < i) maxi.pop();
            while(!mini.empty() && mini.top().second < i) mini.pop();

            if(maxi.top().first - mini.top().first > limit) i++;

            res = max(res, j - i + 1); 
        }
        return res;
    }
};