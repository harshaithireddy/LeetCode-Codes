class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        queue<int> q;
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(!q.empty() && q.front() < i) {
                q.pop();
            }
            int curr = (nums[i] + q.size()) % 2;
            if(curr == 0) {
                if(i > nums.size() - k) return -1;
                res++;
                q.push(i + k - 1);
            } 
        }
        return res;
    }
};