class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> V;
        for(int i = 0; i < nums.size(); i += 3) {
            vector<int> A;
            for(int j = i; j < i+3  && j < nums.size(); j++) {
                A.push_back(nums[j]);
            }
            int diff1 = abs(A[1] - A[0]);
            int diff2 = abs(A[2] - A[1]);
            int diff3 = abs(A[2] - A[0]);

            if(diff1 <= k && diff2 <= k && diff3 <= k) {
                V.push_back(A);
            }
            else return {};
        }
        return V;
    }
};