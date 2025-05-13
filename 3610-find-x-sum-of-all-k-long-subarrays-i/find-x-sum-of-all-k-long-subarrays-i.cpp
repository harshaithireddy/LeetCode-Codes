class Solution {
public:
    int fun(unordered_map<int, int>& mpp, int x) {
        priority_queue<pair<int, int>> pq;
        int res = 0;
        for(auto it : mpp) {
            pq.push({it.second, it.first});
        }

        while(!pq.empty() && x != 0) {
            int a = pq.top().second;
            int b = pq.top().first;
            pq.pop();
            res += (a * b);
            x--;
        }
        return res;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        for(int i = 0; i < k; i++) {
            mpp[nums[i]]++;
        }

        ans.push_back(fun(mpp, x));

        for(int i = k; i < nums.size(); i++) {
            mpp[nums[i - k]]--;
            if(mpp[nums[i - k]] == 0) mpp.erase(nums[i - k]);

            mpp[nums[i]]++;
            ans.push_back(fun(mpp, x));
        }
        return ans;
    }
};