class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int maxValue = INT_MIN;
        int k = nums.size();

        for(int i = 0; i < k; i++) {
            minHeap.push({nums[i][0], i});
            maxValue = max(maxValue, nums[i][0]);
        }

        int minValue = minHeap.top().first;
        vector<int> smallestRange = {minValue, maxValue};

        vector<int> indices(k, 0);
        while(true) {
            int value = minHeap.top().first;
            int index = minHeap.top().second;
            minHeap.pop();

            indices[index]++;
            if(indices[index] >= nums[index].size()) {
                break;
            }

            minHeap.push({nums[index][indices[index]], index});
            minValue = minHeap.top().first;
            maxValue = max(maxValue, nums[index][indices[index]]);
            
            if(maxValue - minValue < smallestRange[1] - smallestRange[0]) {
                smallestRange = {minValue, maxValue};
            }
        }

        return smallestRange;
    }
};