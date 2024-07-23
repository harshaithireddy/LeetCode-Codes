class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> V(201, 0);
        for(int i = 0; i < nums.size(); i++) {
            V[nums[i] + 100]++;
        }
        auto compare = [&](int a, int b) {
            if(V[a + 100] == V[b + 100]) return a > b;
            return V[a + 100] < V[b + 100];
        };
        sort(nums.begin(), nums.end(), compare);
        return nums;
    }
};