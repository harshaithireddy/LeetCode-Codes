class Solution {
private:
    void swap(vector<int>& V, int i, int j) {
        int temp = 0;
        temp = V[i];
        V[i] = V[j];
        V[j] = temp;
        return;
    }

private:
    void Permutations(vector<int>& nums, int start, int end, vector<vector<int>>& res) {
        if(start >= end) {
            res.push_back(nums);
            return;
        }
        for(int i = start; i <= end; i++) {
            swap(nums, start, i);
            Permutations(nums, start+1, end, res);
            swap(nums, start, i);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        Permutations(nums, 0, nums.size() - 1, res);
        return res;
    }
};